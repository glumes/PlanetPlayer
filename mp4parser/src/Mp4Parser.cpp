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
#include "BoxReader.h"
#include "box/Box.h"
#include "box/ContainerBox.h"
#include "box/FileTypeBox.h"
#include "box/MetaDataBox.h"
#include "box/MovieHeaderBox.h"
#include "box/TrackBox.h"

namespace planet {

Mp4Parser::Mp4Parser(std::shared_ptr<BoxReader> reader) {
  this->boxReader = reader;
}

Mp4Parser::~Mp4Parser() {
}

int Mp4Parser::parse(const std::string& path) {
  if (boxReader == nullptr) {
    return RET_FAIL;
  }
  int ret = boxReader->open(path);
  if (ret != RET_OK) {
    return RET_FAIL;
  }
  long fileSize = boxReader->getLength();

  if (fileSize <= 8) {
    return RET_FAIL;
  }
  boxReader->read32();
  uint32_t ftyp = boxReader->read32();
  if (ftyp != FOURCC_ftyp) {
    LOG_INFO("type is not ftyp");
    return RET_FAIL;
  } else {
    LOG_INFO("type is ftyp");
  }

  long currentSize = 0;
  boxReader->setPos(0);
  while (currentSize < fileSize) {
    auto box = readBox(currentSize);
    currentSize += box->getSize();
    boxes.push_back(box);
    LOG_INFO("boxes push back size is {} and boxes size is {}", box->size, boxes.size());
    boxReader->setPos(currentSize);
  }
  return 0;
}

std::shared_ptr<Box> Mp4Parser::readBox(long startPos) const {
  int index = 0;
  uint32_t size = boxReader->read32();
  uint32_t type = boxReader->read32();
  index = 8;
  if (size == 1) {
    index += 8;
    size = boxReader->read64();
  }
  LOG_INFO("mp4 parser read box and size is {}", size);
  auto box = allocBox(type, size);
  box->setStartPos(startPos);
  box->parse(const_cast<Mp4Parser*>(this), startPos);
  return box;
}

std::shared_ptr<BoxReader> Mp4Parser::getReader() const {
  return boxReader;
}

std::shared_ptr<Box> Mp4Parser::allocBox(FourCC type, uint32_t size) const {
  std::shared_ptr<Box> box = nullptr;
  switch (type) {
    case FOURCC_moov:
      box = std::make_shared<ContainerBox>(type, size);
      break;
    case FOURCC_ftyp:
      box = std::make_shared<FileTypeBox>(type, size);
      break;
    case FOURCC_mvhd:
      box = std::make_shared<MovieHeaderBox>(type, size);
      break;
    case FOURCC_meta:
      box = std::make_shared<MetaDataBox>(type, size);
      break;
    case FOURCC_trak:
      box = std::make_shared<TrackBox>(type, size);
      break;
    default:
      box = std::make_shared<Box>(type, size);
      break;
  }
  return box;
}

// int Mp4Parser::addBox(const std::shared_ptr<Box> box) const {
//   return 0;
// }
}  // namespace planet
