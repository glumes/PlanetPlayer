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
#include "mp4/box/FtypBox.h"
namespace planet {
    std::shared_ptr<FtypBox> planet::FtypBox::Create(planet::BOX_Size size, std::shared_ptr<ByteStreamReader> reader) {
        return std::make_shared<FtypBox>(size,reader);
    }

    FtypBox::FtypBox(BOX_Size size, std::shared_ptr<ByteStreamReader> reader): Box(FOURCC_ftyp,size) {
        if (size < BOX_HEADER_SIZE + 8) return;
        reader->readUI32(mMajorBrand);
        reader->readUI32(mMinorVersion);
        size -=16;
        while (size>=4){
            BOX_UI32 compatible_brand;
            RET result = reader->readUI32(compatible_brand);
            if (BOX_FAILED(result)) return;
            mCompatibleBrands.push_back(compatible_brand);
            size-=4;
        }
    }
}
