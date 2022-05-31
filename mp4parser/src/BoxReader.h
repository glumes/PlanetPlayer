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
#include "base/ParserDefine.h"

namespace planet {

class BoxReader {
 public:
  BoxReader();
  ~BoxReader();

  int open(const std::string& path);
  int close();

  long getLength();
  long getPos();
  int setPos(long pos);
  uint8_t read8();
  uint16_t read16();
  uint32_t read24();
  uint32_t read32();
  uint64_t read64();
  int skip(int len);
  int readBuffer(char* buffer,int len);

 private:
  FILE* file;
};

}  // namespace planet
