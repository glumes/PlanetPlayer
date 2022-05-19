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

#include "BoxReader.h"
#include "FourCC.h"
namespace planet {

#define DECLARE_BOX_METHODS(T)                                                        \
  T();                                                                                \
  virtual ~T();                                                                       \
  virtual bool parse(const std::shared_ptr<BoxReader>& reader) override;              \
  virtual FourCC BoxType() const override;                                            \

class Box {
 public:
  virtual ~Box();
  virtual bool parse(const std::shared_ptr<BoxReader>& reader) = 0;
  virtual FourCC BoxType() const = 0;
};

}  // namespace planet
