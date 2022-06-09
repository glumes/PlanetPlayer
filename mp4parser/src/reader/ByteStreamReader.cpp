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

#include "reader/ByteStreamReader.h"

namespace planet {

RET ByteStreamReader::read(void* buffer, BOX_Size bytesToRead) {
  if (bytesToRead == 0) return RET_OK;
  BOX_Size bytesRead;
  while (bytesToRead) {
    RET result = readPartial(buffer, bytesToRead, bytesRead);
    if (BOX_FAILED(result)) return result;
    if (bytesRead == 0) return BOX_ERROR_INTERNAL;
    bytesToRead -= bytesRead;
    buffer = (void*)(((BOX_Byte*)buffer) + bytesRead);
  }
  return RET_OK;
}

RET ByteStreamReader::readDouble(double& value) {
  unsigned char buffer[8];
  RET ret = read((void*)buffer, 8);
  if (BOX_FAILED(ret)) {
    value = 0;
    return ret;
  }
  value = BytesToDoubleBE(buffer);
  return RET_OK;
}

RET ByteStreamReader::readUI64(BOX_UI64& value) {
  unsigned char buffer[8];
  RET ret = read((void*)buffer, 8);
  if (BOX_FAILED(ret)) {
    value = 0;
    return ret;
  }
  value = BytesToUInt64BE(buffer);
  return RET_OK;
}

RET ByteStreamReader::readUI32(BOX_UI32& value) {
  unsigned char buffer[4];
  RET ret = read((void*)buffer, 4);
  if (BOX_FAILED(ret)) {
    value = 0;
    return ret;
  }
  value = BytesToUInt32BE(buffer);
  return RET_OK;
}

RET ByteStreamReader::readUI24(BOX_UI32& value) {
  unsigned char buffer[3];
  RET ret = read((void*)buffer, 3);
  if (BOX_FAILED(ret)) {
    value = 0;
    return ret;
  }
  value = BytesToUInt24BE(buffer);
  return RET_OK;
}

RET ByteStreamReader::readUI16(BOX_UI16& value) {
  unsigned char buffer[2];
  RET ret = read((void*)buffer, 2);
  if (BOX_FAILED(ret)) {
    value = 0;
    return ret;
  }
  value = BytesToUInt16BE(buffer);
  return RET_OK;
}

RET ByteStreamReader::readUI08(BOX_UI08& value) {
  unsigned char buffer[1];
  RET ret = read((void*)buffer, 1);
  if (BOX_FAILED(ret)) {
    value = 0;
    return ret;
  }
  value = buffer[0];
  return RET_OK;
}
}  // namespace planet