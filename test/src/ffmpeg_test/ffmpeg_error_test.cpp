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

#ifdef __cplusplus
extern "C" {
#endif
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libavutil/parseutils.h>
#include <libavcodec/avcodec.h>
#include <libswscale/swscale.h>
#include <libavutil/error.h>

#ifdef __cplusplus
}
#endif

#include "utils/Log.h"

namespace planet {
    TEST(PlanetTest, ffmpeg_error_test) {
        GLUMES_LOG_INFO("test log and arg is {} and str is {}",1,"string");
        // 通过 av_log 打印日志
        av_log(nullptr, AV_LOG_INFO, "this is info log\n");
        // 设置日志打印级别
        av_log_set_level(AV_LOG_INFO);
        // 获取日志打印级别
        int level = av_log_get_level();
        av_log(nullptr, AV_LOG_INFO, "log level is %d\n", level);

        GLUMES_LOG_INFO("ffmepg again is {}",AVERROR(EAGAIN));

        char buf[1024];
        av_make_error_string(buf,1024,AVERROR_EXTERNAL);
        GLUMES_LOG_INFO("ffmpeg log info is {}",buf);

        char errstr[1024];
        av_strerror(AVERROR_DEMUXER_NOT_FOUND, errstr, 1024);
        GLUMES_LOG_INFO("ffmpeg log info is {}",errstr);

    }
}