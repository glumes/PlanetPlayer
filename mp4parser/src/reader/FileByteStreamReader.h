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
#include "reader/ByteStreamReader.h"

namespace planet {
class FileByteStreamReader : public ByteStreamReader {
 public:
  static RET Create(const std::string& path);
  explicit FileByteStreamReader(const std::string& path);
  virtual RET readPartial(void* buffer, BOX_Size bytesToRead, BOX_Size& bytesRead) override;
  virtual RET seek(BOX_Position position) override;
  virtual RET tell(BOX_Position& position) override;
  virtual RET getSize(BOX_LargeSize& size) override;

 private:
  FILE* mFile;
  BOX_Position mPosition;
  BOX_Size mSize;
};
}  // namespace planet