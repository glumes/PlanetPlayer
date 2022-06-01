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
#include "base/ParserDefine.h"
namespace planet {
class BoxUtils {
 public:
};

inline BOX_UI64 BytesToUInt64BE(const unsigned char* bytes) {
  return (((BOX_UI64)bytes[0]) << 56) | (((BOX_UI64)bytes[1]) << 48) |
         (((BOX_UI64)bytes[2]) << 40) | (((BOX_UI64)bytes[3]) << 32) |
         (((BOX_UI64)bytes[4]) << 24) | (((BOX_UI64)bytes[5]) << 16) | (((BOX_UI64)bytes[6]) << 8) |
         (((BOX_UI64)bytes[7]));
}

inline double BytesToDoubleBE(const unsigned char* bytes) {
  BOX_UI64 i_value = BytesToUInt64BE(bytes);
  void* v_value = reinterpret_cast<void*>(&i_value);
  double* d_value = reinterpret_cast<double*>(v_value);
  return *d_value;
}

inline BOX_UI32 BytesToUInt32BE(const unsigned char* bytes) {
  return (((BOX_UI32)bytes[0]) << 24) | (((BOX_UI32)bytes[1]) << 16) | (((BOX_UI32)bytes[2]) << 8) |
         (((BOX_UI32)bytes[3]));
}

inline BOX_SI32 BytesToInt32BE(const unsigned char* bytes) {
  return BytesToUInt32BE(bytes);
}

inline BOX_UI32 BytesToUInt24BE(const unsigned char* bytes) {
  return (((BOX_UI32)bytes[0]) << 16) | (((BOX_UI32)bytes[1]) << 8) | (((BOX_UI32)bytes[2]));
}

inline BOX_UI16 BytesToUInt16BE(const unsigned char* bytes) {
  return (((BOX_UI16)bytes[0]) << 8) | (((BOX_UI16)bytes[1]));
}

}  // namespace planet