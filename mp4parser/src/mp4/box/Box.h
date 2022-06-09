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
#include "FourCC.h"
#include "base/ParserDefine.h"
#include "reader/ByteStreamReader.h"

namespace planet {
    const BOX_UI32 BOX_HEADER_SIZE = 8;
    const BOX_UI32 BOX_HEADER_SIZE_64 = 16;
    const BOX_UI32 FULL_BOX_HEADER_SIZE = 12;
    const BOX_UI32 FULL_BOX_HEADER_SIZE_64 = 20;

class BoxParent;
class Box {
 public:
  Box(Type type, BOX_UI64 size);

  BOX_UI32 getFlags() const {
    return mFlags;
  }
  void setFlags(BOX_UI32 flags) {
    mFlags = flags;
  }
  BOX_UI08 getVersion() const {
    return mVersion;
  }
  void setVersion(BOX_UI08 version) {
    mVersion = version;
  }
  Type getType() const {
    return mType;
  }
  void setType(Type type) {
    mType = type;
  }

  BOX_UI64 getSize() const {
    return mSize64;
  }
  void setSize(BOX_UI64 size) {
    mSize64 = size;
  }

  virtual void setParent(BoxParent* parent) {
    mParent = parent;
  }

  virtual BoxParent* getParent() {
    return mParent;
  }

 protected:
  Type mType;
  BOX_UI64 mSize64;
  BOX_UI08 mVersion;
  BOX_UI32 mFlags;
  BoxParent* mParent;
};

class BoxParent {
 public:
  std::vector<std::shared_ptr<Box>>& getChildren() {
    return mChildren;
  }
  virtual RET addChild(std::shared_ptr<Box> box, int position = -1);
  virtual RET removeChild(std::shared_ptr<Box> box);
  virtual RET deleteChild(Type type);

 private:
  RET addChildAt(std::shared_ptr<Box> box, int position);
  RET removeChildAt(int index);

 protected:
  std::vector<std::shared_ptr<Box>> mChildren = {};
};
}  // namespace planet