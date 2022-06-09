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

#include "gtest/gtest.h"
#include "mp4parser/src/BoxReader.h"
#include "mp4parser/src/FourCC.h"
#include "mp4parser/src/Mp4Parser.h"

#include "base/Define.h"
#include "reader/FileByteStreamReader.h"
#include "utils/Log.h"

namespace planet {
TEST(file_byte_stream_test, file_read_test) {
  std::string path = std::string(PROJECT_DIR_PATH) + "/resource/video/video-640x360.mp4";
  std::shared_ptr<ByteStreamReader> reader = nullptr;
  auto ret = FileByteStreamReader::Create(reader, path);
  if (ret == RET_OK) {
    BOX_LargeSize size = 0;
    reader->getSize(size);
    LOG_INFO("create file read success and size is %lld", size);
  } else {
    LOG_INFO("create file read failed");
  }
}
}  // namespace planet