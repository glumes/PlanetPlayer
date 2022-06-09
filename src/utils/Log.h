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
#include "spdlog/spdlog.h"

#define LOG_TRACE(...) \
  SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::trace, __VA_ARGS__)
#define LOG_INFO(...) \
  SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::info, __VA_ARGS__)
#define LOG_DEBUG(...) \
  SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::debug, __VA_ARGS__)
#define LOG_WARN(...) \
  SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::warn, __VA_ARGS__)
#define LOG_ERROR(...) \
  SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::err, __VA_ARGS__)
#define LOG_CRITICAL(...) \
  SPDLOG_LOGGER_CALL(Log::getCoreLogger(), spdlog::level::level_enum::critical, __VA_ARGS__)

namespace planet {

class Log {
 public:
  static void init();
  static std::shared_ptr<spdlog::logger>& getCoreLogger() {
    return mCoreLogger;
  }

 private:
  static std::shared_ptr<spdlog::logger> mCoreLogger;
};
}  // namespace planet
