/**
 * ,------. ,--.                        ,--.      ,------. ,--.
 * |  .--. '|  | ,--,--.,--,--, ,---. ,-'  '-.    |  .--. '|  | ,--,--.,--. ,--.,---. ,--.--.
 * |  '--' ||  |' ,-.  ||      \ .-. :'-.  .-'    |  '--' ||  |' ,-.  | \  '  /| .-. :|  .--'
 * |  | --' |  |\ '-'  ||  ||  \   --.  |  |      |  | --' |  |\ '-'  |  \   ' \   --.|  |
 * `--'     `--' `--`--'`--''--'`----'  `--'      `--'     `--' `--`--'.-'  /   `----'`--'
 *                                                                     `---'
 * Planet Player 播放器项目实践
 * 音视频开发进阶知识星球专栏文章
 *
 * 作者：星陨
 * 微信：ezglumes
 * 微信公众号：音视频开发进阶
 * 知识星球：音视频开发进阶
 * 博客网站：https://glumes.com
 *
 * 欢迎联系交流！！！
 */

#include "gtest/gtest.h"
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libavutil/parseutils.h>
#include <libavcodec/avcodec.h>
#include <libswscale/swscale.h>
#ifdef __cplusplus
}
#endif

#define INBUF_SIZE 4096

namespace planet {

    static void log_callback(void *ptr, int level, const char *fmt, va_list vaList) {
        vfprintf(stdout,fmt,vaList);
    }

    static void
    encode(AVCodecContext *encodeCtx, AVFrame *frame, AVPacket *pkt, struct SwsContext *swsCtx, FILE *outputFile) {
        int ret;
        ret = avcodec_send_frame(encodeCtx, frame);
        while (ret >= 0) {
            ret = avcodec_receive_packet(encodeCtx, pkt);
            if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
                return;
            else if (ret < 0) {
                fprintf(stderr, "Error during encoding\n");
                exit(1);
            }
            fwrite(pkt->data, 1, pkt->size, outputFile);
            fprintf(stderr, "encode write frame\n");
            av_packet_unref(pkt);
        }
    }

    static void convert(AVCodecContext *decodeCtx, AVFrame *decodeFrame, AVPacket *decodePkt,
                        AVCodecContext *encodeCtx, AVFrame *encodeFrame, AVPacket *encodePkt,
                        struct SwsContext *swsCtx, FILE *outputFile) {
        int ret;

        ret = avcodec_send_packet(decodeCtx, decodePkt);
        if (ret < 0) {
            fprintf(stderr, "Error sending a packet for decoding\n");
            exit(1);
        }

        while (ret >= 0) {
            ret = avcodec_receive_frame(decodeCtx, decodeFrame);
            if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
                return;
            else if (ret < 0) {
                fprintf(stderr, "Error during decoding\n");
                exit(1);
            }

            sws_scale(swsCtx, decodeFrame->data, decodeFrame->linesize, 0, decodeFrame->height, encodeFrame->data,
                      encodeFrame->linesize);

            encode(encodeCtx, encodeFrame, encodePkt, swsCtx, outputFile);
        }
    }


    TEST(PlanetTest, scale_H264_test) {
        av_log_set_level(AV_LOG_INFO);
        av_log_set_callback(log_callback);

        const AVCodec *decodeCodec;
        AVCodecParserContext *parser;
        AVCodecContext *decodeCtx = NULL;
        FILE *inputFile;
        FILE *outputFile;
        AVFrame *decodeFrame;
        uint8_t inbuf[INBUF_SIZE + AV_INPUT_BUFFER_PADDING_SIZE];
        uint8_t *data;
        size_t data_size;
        int ret;
        AVPacket *decodePkt;
        decodePkt = av_packet_alloc();

        struct SwsContext *swsCtx;

        memset(inbuf + INBUF_SIZE, 0, AV_INPUT_BUFFER_PADDING_SIZE);

        AVPacket *encodePkt;
        encodePkt = av_packet_alloc();

        decodeCodec = avcodec_find_decoder(AV_CODEC_ID_H264);
        parser = av_parser_init(decodeCodec->id);

        decodeCtx = avcodec_alloc_context3(decodeCodec);
        avcodec_open2(decodeCtx, decodeCodec, nullptr);

        std::string path = std::string(PROJECT_DIR_PATH) + "/resource/video/video-640x480.h264";
        inputFile = fopen(path.c_str(), "rb");

        std::string outputPath = std::string(PROJECT_DIR_PATH) + "/resource/out/video-320x240.h264";
        outputFile = fopen(outputPath.c_str(), "wb");

        decodeFrame = av_frame_alloc();

        // 编码相关的设置
        AVCodecContext *encodeCtx = nullptr;
        const AVCodec *encodeCodec = nullptr;
        encodeCodec = avcodec_find_encoder(AV_CODEC_ID_H264);
        if (!encodeCodec) {

        }
        encodeCtx = avcodec_alloc_context3(encodeCodec);
        encodeCtx->width = 320;
        encodeCtx->height = 240;
        encodeCtx->time_base = (AVRational) {1, 25};
        encodeCtx->framerate = (AVRational) {25, 1};
        encodeCtx->gop_size = 25;
        encodeCtx->pix_fmt = AV_PIX_FMT_YUV420P;
        encodeCtx->bit_rate = 3000000;

        AVFrame *encodeFrame = av_frame_alloc();
        encodeFrame->format = encodeCtx->pix_fmt;
        encodeFrame->width = encodeCtx->width;
        encodeFrame->height = encodeCtx->height;

        av_frame_get_buffer(encodeFrame, 0);
        av_frame_make_writable(encodeFrame);

        avcodec_open2(encodeCtx, encodeCodec, nullptr);

        swsCtx = sws_getContext(640, 480, AV_PIX_FMT_YUV420P, 320, 240, AV_PIX_FMT_YUV420P, SWS_BILINEAR, nullptr,
                                nullptr,
                                nullptr);

        while (!feof(inputFile)) {
            data_size = fread(inbuf, 1, INBUF_SIZE, inputFile);
            if (!data_size)
                break;

            data = inbuf;
            while (data_size > 0) {
                ret = av_parser_parse2(parser, decodeCtx, &decodePkt->data, &decodePkt->size,
                                       data, data_size, AV_NOPTS_VALUE, AV_NOPTS_VALUE, 0);
                if (ret < 0) {
                    fprintf(stderr, "Error while parsing\n");
                    exit(1);
                }
                data += ret;
                data_size -= ret;

                if (decodePkt->size) {
                    convert(decodeCtx, decodeFrame, decodePkt, encodeCtx, encodeFrame, encodePkt, swsCtx, outputFile);
                }
            }
        }

        av_parser_close(parser);

        avcodec_free_context(&decodeCtx);
        av_frame_free(&decodeFrame);
        av_packet_free(&decodePkt);

        avcodec_free_context(&encodeCtx);
        av_frame_free(&encodeFrame);
        av_packet_free(&encodePkt);
        return;
    }
}