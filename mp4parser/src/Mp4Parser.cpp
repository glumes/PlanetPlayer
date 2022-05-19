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
#include "Mp4Parser.h"
#include "box/Box.h"
#include "BoxReader.h"

namespace planet {

Mp4Parser::Mp4Parser(std::shared_ptr<BoxReader> reader) {
  this->boxReader = reader;
}

Mp4Parser::~Mp4Parser() {

}

int Mp4Parser::parse(const std::string& path) {
  if (boxReader == nullptr){
    return RET_FAIL;
  }
  int ret = boxReader->open(path);
  if (ret != RET_OK){
    return RET_FAIL;
  }
  long fileSize = boxReader->getLength();
  long currentSize = 0;
  boxReader->setPos(0);
  while (currentSize < fileSize){
    auto box = readBox(currentSize);
    currentSize += box->size;
    boxes.push_back(box);
    boxReader->setPos(currentSize);
  }
  return 0;
}

std::shared_ptr<Box> Mp4Parser::readBox(long startPos) {
  int index = 0;
  uint32_t size = boxReader->read32();
  uint32_t type = boxReader->read32();
  index = 8;
  if (size == 1){
    index += 8;
    size = boxReader->read64();
  }
  auto box = allocBox(type,size);
  box->startPos = startPos;
  box->parse(this,startPos);
  return box;
}

std::shared_ptr<Box> Mp4Parser::allocBox(uint32_t type,uint32_t size) {
  return std::make_shared<Box>();
}

}  // namespace planet
