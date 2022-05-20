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
#include <vector>
#include <memory>

namespace planet {

class Box;
class BoxReader;

class Mp4Parser {
 public:
  Mp4Parser(std::shared_ptr<BoxReader> reader);
  ~Mp4Parser();
  int parse(const std::string& path);
  std::shared_ptr<Box> readBox(long position);
  const std::shared_ptr<BoxReader> getReader() const;

 private:
  void init() {};
  std::vector<std::shared_ptr<Box>> boxes = {};
  std::shared_ptr<BoxReader> boxReader = nullptr;
  std::shared_ptr<Box> allocBox(uint32_t type,uint32_t size);
};

}  // namespace planet


