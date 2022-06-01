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
#include <string>
#include <vector>
#include "base/Define.h"

namespace planet {

typedef unsigned int BOX_UI32;
typedef signed int BOX_SI32;
typedef unsigned short BOX_UI16;
typedef signed short BOX_SI16;
typedef unsigned char BOX_UI08;

typedef BOX_UI08 BOX_Byte;
typedef BOX_UI32 BOX_Size;

typedef long long BOX_SI64;
typedef unsigned long long BOX_UI64;
typedef unsigned long long BOX_LargeSize;
typedef long long BOX_Offset;
typedef unsigned long long BOX_Position;

#define BOX_fseek fseeko
#define Box_ftell ftello

#define BOX_FAILED(result) ((result) != RET_OK)
#define BOX_SUCCEEDED(result) ((result) == RET_OK)

#define BOX_ERROR_INTERNAL -2
#define BOX_ERROR_EOS -3
#define BOX_ERROR_READ_FAILED -4
#define BOX_ERROR_INVALID_PARAMETERS -5

#define BOX_LIST std::vector<std::shared_ptr<Box>>
#define BOX std::shared_ptr<Box>
}  // namespace planet