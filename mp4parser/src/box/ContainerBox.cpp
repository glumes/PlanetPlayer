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

#include "box/ContainerBox.h"

namespace planet {
ContainerBox::ContainerBox(FourCC type, uint32_t size) : Box(type, size) {
}

ContainerBox::~ContainerBox() {
}

// FourCC ContainerBox::BoxType() const {
//   return FOURCC_moov;
// }

int ContainerBox::parse(Mp4Parser* parser, uint32_t startPos) {
  uint32_t index = 0;
  while (index < this->size - 8) {
    auto box = parser->readBox(startPos + index);
    children.emplace_back(box);
    index += box->getSize();
    parser->getReader()->setPos(startPos + index);
  }
  return RET_OK;
}
}  // namespace planet