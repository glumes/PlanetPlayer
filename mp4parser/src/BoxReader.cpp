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
#include "BoxReader.h"

namespace planet {
BoxReader::BoxReader() {
  file = nullptr;
}

BoxReader::~BoxReader() {
  close();
}

int BoxReader::open(const std::string& path) {
  file = fopen(path.c_str(),"rb");
  if (file == nullptr){
    return RET_FAIL;
  }
  return RET_OK;
}

int BoxReader::close() {
  if (file){
    fclose(file);
    file = nullptr;
  }
  return RET_FAIL;
}

long BoxReader::getLength() {
  long cur = ftell(file);
  fseek(file,0,SEEK_END);
  long length = ftell(file);
  fseek(file,cur,SEEK_SET);
  return length;
}

long BoxReader::getPos() {
  return ftell(file);
}

int BoxReader::setPos(long pos) {
  fseek(file,pos,SEEK_END);
  return RET_OK;
}

uint8_t BoxReader::read8() {
  uint8_t ret;
  fread(&ret,1,1,file);
  return ret;
}

uint16_t BoxReader::read16() {
  uint8_t buffer[2];
  fread(buffer,2,1,file);
  return ((buffer[0] << 8 | buffer[1]));
}

uint32_t BoxReader::read24() {
  uint8_t buffer[3];
  fread(buffer,3,1,file);
  return ((buffer[1] << 16) | (buffer[1] << 8) | buffer[2]);
}

uint32_t BoxReader::read32() {
  uint8_t buffer[4];
  fread(buffer, 4, 1, file);
  return ((buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3]);
}

uint64_t BoxReader::read64() {
  uint64_t h = read32();
  uint64_t l = read32();
  return (h<<32) | l;
}

int BoxReader::skip(int len) {
  return fseek(file,len,SEEK_SET);
}

int BoxReader::readBuffer(char* buffer, int len) {
  return fread(buffer,1,len,file);
}

}