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
#include "BoxFactory.h"
namespace planet {
  RET BoxFactory::createBoxFromStream(std::shared_ptr<ByteStreamReader> reader,
                                            planet::BOX_LargeSize &bytesAvailable,
                                            std::shared_ptr<Box> &box) {
        RET result;
        box = nullptr;
      if (bytesAvailable < 8) return BOX_ERROR_EOS;
      BOX_Position start;
      reader->tell(start);

      BOX_UI32 size;
      result = reader->readUI32(size);
      if (BOX_FAILED(result)){
          reader->seek(start);
          return result;
      }
      Type type ;
      result = reader->readUI32(type);
      if (BOX_FAILED(result)){
          reader->seek(start);
          return result;
      }
        return 0;
    }
}