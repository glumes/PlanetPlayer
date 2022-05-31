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
#include "base/BoxUtils.h"
#include "base/ParserDefine.h"

namespace planet {
class ByteStreamReader {
 public:
  virtual RET readPartial(void* buffer, BOX_Size bytesToRead, BOX_Size& bytesRead) = 0;
  RET read(void* buffer, BOX_Size bytesToRead);
  RET readDouble(double& value);
  RET readUI64(BOX_UI64& value);
  RET readUI32(BOX_UI32& value);
  RET readUI24(BOX_UI32& value);
  RET readUI16(BOX_UI16& value);
  RET readUI08(BOX_UI08& value);

  virtual RET seek(BOX_Position position) = 0;
  virtual RET tell(BOX_Position& position) = 0;
  virtual RET getSize(BOX_LargeSize& size) = 0;
};
}  // namespace planet