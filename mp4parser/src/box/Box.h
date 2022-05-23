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

#include "BoxReader.h"
#include "FourCC.h"
#include "Mp4Parser.h"
#include "utils/Log.h"

namespace planet {

#define DECLARE_BOX_METHODS(T)                                      \
  T(FourCC type, uint32_t size);                                    \
  virtual ~T();                                                     \
  virtual int parse(Mp4Parser* parser, uint32_t startPos) override; \
  //  virtual FourCC BoxType() const override;

class Box {
 public:
  Box(FourCC type, uint32_t size) {
    this->type = type;
    this->size = size;
    this->startPos = 0;
  };
  virtual ~Box(){};
  virtual int parse(Mp4Parser*, uint32_t) {
    return RET_FAIL;
  };
  virtual FourCC BoxType() const {
    return type;
  };
  uint32_t getSize() const {
    return size;
  }
  uint32_t getStartPos() const {
    return startPos;
  }
  void setStartPos(uint32_t startPos) {
    this->startPos = startPos;
  }

 protected:
  uint32_t size;
  FourCC type;
  uint32_t startPos;
  std::vector<std::shared_ptr<Box>> children = {};
  friend class Mp4Parser;
};

}  // namespace planet
