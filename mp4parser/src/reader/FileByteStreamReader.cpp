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

#include "reader/FileByteStreamReader.h"

namespace planet {

FileByteStreamReader::FileByteStreamReader(const std::string& path) {
}

RET FileByteStreamReader::readPartial(void* buffer, BOX_Size bytesToRead, BOX_Size& bytesRead) {
  auto readNum = fread(buffer, 1, bytesToRead, mFile);
  if (readNum > 0) {
    bytesRead = (BOX_Size)readNum;
    mPosition += readNum;
    return RET_OK;
  } else if (feof(mFile)) {
    bytesRead = 0;
    return BOX_ERROR_EOS;
  } else {
    bytesRead = 0;
    return BOX_ERROR_READ_FAILED;
  }
}

RET FileByteStreamReader::seek(BOX_Position position) {
  if (position == mPosition) return RET_OK;
  auto ret = BOX_fseek(mFile, position, SEEK_SET);
  if (ret == 0) {
    mPosition = position;
    return RET_OK;
  }
  return RET_FAIL;
}

RET FileByteStreamReader::tell(BOX_Position& position) {
  position = mPosition;
  return RET_OK;
}

RET FileByteStreamReader::getSize(BOX_LargeSize& size) {
  size = mSize;
  return RET_OK;
}

RET FileByteStreamReader::Create(const std::string& path) {
  return 0;
}

}  // namespace planet