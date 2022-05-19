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
namespace planet {

Mp4Parser::Mp4Parser(const std::shared_ptr<BoxReader> reader) {
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
//    currentSize += box->size();
    boxReader->setPos(currentSize);
  }
  return 0;
}

std::shared_ptr<Box> Mp4Parser::readBox(long) {
  return std::shared_ptr<Box>();
}

}  // namespace planet
