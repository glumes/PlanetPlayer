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
#include "utils/Log.h"

namespace planet {
TEST(box_reader_test, test_read_ftyp) {
  std::string path = std::string(PROJECT_DIR_PATH) + "/resource/video/video-640x360.mp4";
  auto reader = std::make_shared<BoxReader>();
  int ret = reader->open(path);
  if (ret != RET_OK) {
    LOG_INFO("open file failed\n");
  }

  long length = reader->getLength();
  LOG_INFO("file length is {}", length);

  reader->setPos(0);
  auto size = reader->read32();
  LOG_INFO("read size is {}", size);

  FourCC ftyp = reader->read32();
  if (ftyp == FOURCC_ftyp) {
    LOG_INFO("read ftyp success and value is {}", ftyp);
  } else {
    LOG_INFO("read ftyp failed and value is {}", ftyp);
  }
}

TEST(box_reader_test, mp4_parser_test) {
  std::string path = std::string(PROJECT_DIR_PATH) + "/resource/video/video-640x360.mp4";
  auto reader = std::make_shared<BoxReader>();

  auto mp4Parser = std::make_shared<Mp4Parser>(reader);
  auto ret = mp4Parser->parse(path);
}

}  // namespace planet