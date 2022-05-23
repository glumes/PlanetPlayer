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
#include "box/MovieHeaderBox.h"

namespace planet{
MovieHeaderBox::MovieHeaderBox(FourCC type, uint32_t size) : Box(type, size) {
}

MovieHeaderBox::~MovieHeaderBox() {
}

int MovieHeaderBox::parse(Mp4Parser* parser, uint32_t startPos) {
  auto reader = parser->getReader();
  reader->setPos(startPos);
  uint64_t creationTime, modificationTime;
  uint32_t timeScale, duration;
  uint8_t version = reader->read8();
  // read flag
  reader->read24();
  if (version == 1) {
    creationTime = reader->read64();
    modificationTime = reader->read64();
    timeScale = reader->read32();
    duration = reader->read32();
  } else {
    creationTime = reader->read32();
    modificationTime = reader->read32();
    timeScale = reader->read32();
    duration = reader->read32();
  }
  parser->duration = duration;
  parser->timescale = timeScale;
  return RET_OK;
}
}