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
#include "mp4/box/Box.h"

namespace planet {
Box::Box(Type type, BOX_UI64 size)
    : mType(type), mSize64(size), mVersion(0), mFlags(0), mParent(nullptr) {
}

RET BoxParent::addChild(std::shared_ptr<Box> box, int position) {
  if (box->getParent() != nullptr) {
    return BOX_ERROR_INVALID_PARAMETERS;
  }
  addChildAt(box, position);
  return 0;
}

RET BoxParent::removeChild(std::shared_ptr<Box> child) {
  return 0;
}
RET BoxParent::deleteChild(Type type) {
  return 0;
}

RET BoxParent::addChildAt(std::shared_ptr<Box> box, int position) {
  if (position < 0) {
    position = (int)mChildren.size();
  }
  mChildren.insert(mChildren.begin() + position, box);
  return RET_OK;
}

}  // namespace planet