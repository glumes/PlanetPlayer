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

#pragma once
#include <iostream>
namespace planet {

#define MKTAG(a, b, c, d) ((d) | ((c) << 8) | ((b) << 16) | ((unsigned)(a) << 24))

// enum class FourCC {
//   FOURCC_ftyp = MKTAG('f', 't', 'y', 'p'),
//   FOURCC_moov = MKTAG('m', 'o', 'o', 'v'),
//   FOURCC_mvhd = MKTAG('m', 'v', 'h', 'd'),
//   FOURCC_trak = MKTAG('t', 'r', 'a', 'k'),
//   FOURCC_tkhd = MKTAG('t', 'k', 'h', 'd'),
//   FOURCC_mdia = MKTAG('m', 'd', 'i', 'a'),
//   FOURCC_mdhd = MKTAG('m', 'd', 'h', 'd'),
//   FOURCC_hdlr = MKTAG('h', 'd', 'l', 'r'),
//   FOURCC_minf = MKTAG('m', 'i', 'n', 'f'),
//   FOURCC_stbl = MKTAG('s', 't', 'b', 'l'),
//   FOURCC_stsd = MKTAG('s', 't', 's', 'd'),
//   FOURCC_stts = MKTAG('s', 't', 't', 's'),
//   FOURCC_stss = MKTAG('s', 't', 's', 's'),
//   FOURCC_ctts = MKTAG('c', 't', 't', 's'),
//   FOURCC_stco = MKTAG('s', 't', 'c', 'o'),
//   FOURCC_co64 = MKTAG('c', 'o', '6', '4'),
//   FOURCC_stsc = MKTAG('s', 't', 's', 'c'),
//   FOURCC_stsz = MKTAG('s', 't', 's', 'z'),
//   FOURCC_stz2 = MKTAG('s', 't', 'z', '2'),
//   FOURCC_udta = MKTAG('u', 'd', 't', 'a'),
//   FOURCC_meta = MKTAG('m', 'e', 't', 'a'),
//   FOURCC_dinf = MKTAG('d', 'i', 'n', 'f'),
//   FOURCC_pitm = MKTAG('p', 'i', 't', 'm'),
//   FOURCC_iinf = MKTAG('i', 'i', 'n', 'f'),
//   FOURCC_iref = MKTAG('i', 'r', 'e', 'f'),
//   FOURCC_iloc = MKTAG('i', 'l', 'o', 'c'),
// };

typedef uint32_t FourCC;
typedef uint32_t Type;

#define FOURCC_ftyp MKTAG('f', 't', 'y', 'p')
#define FOURCC_moov MKTAG('m', 'o', 'o', 'v')
#define FOURCC_mvhd MKTAG('m', 'v', 'h', 'd')
#define FOURCC_trak MKTAG('t', 'r', 'a', 'k')
#define FOURCC_tkhd MKTAG('t', 'k', 'h', 'd')
#define FOURCC_mdia MKTAG('m', 'd', 'i', 'a')
#define FOURCC_mdhd MKTAG('m', 'd', 'h', 'd')
#define FOURCC_hdlr MKTAG('h', 'd', 'l', 'r')
#define FOURCC_minf MKTAG('m', 'i', 'n', 'f')
#define FOURCC_stbl MKTAG('s', 't', 'b', 'l')
#define FOURCC_stsd MKTAG('s', 't', 's', 'd')
#define FOURCC_stts MKTAG('s', 't', 't', 's')
#define FOURCC_stss MKTAG('s', 't', 's', 's')
#define FOURCC_ctts MKTAG('c', 't', 't', 's')
#define FOURCC_stco MKTAG('s', 't', 'c', 'o')
#define FOURCC_co64 MKTAG('c', 'o', '6', '4')
#define FOURCC_stsc MKTAG('s', 't', 's', 'c')
#define FOURCC_stsz MKTAG('s', 't', 's', 'z')
#define FOURCC_stz2 MKTAG('s', 't', 'z', '2')
#define FOURCC_udta MKTAG('u', 'd', 't', 'a')
#define FOURCC_meta MKTAG('m', 'e', 't', 'a')
#define FOURCC_dinf MKTAG('d', 'i', 'n', 'f')
#define FOURCC_pitm MKTAG('p', 'i', 't', 'm')
#define FOURCC_iinf MKTAG('i', 'i', 'n', 'f')
#define FOURCC_iref MKTAG('i', 'r', 'e', 'f')
#define FOURCC_iloc MKTAG('i', 'l', 'o', 'c')

// heif
//#define FOURCC_iprp MKTAG('i','p','r','p')
//#define FOURCC_ipco MKTAG('i','p','c','o')
//#define FOURCC_ipma MKTAG('i','p','m','a')
//
//
//#define HANDLER_VIDEO MKTAG('v','i','d','e')
//#define HANDLER_AUDIO MKTAG('s','o','u','n')
//#define HANDLER_HINT MKTAG('h','i','n','t')
//#define HANDLER_META MKTAG('m','e','t','a')
}
