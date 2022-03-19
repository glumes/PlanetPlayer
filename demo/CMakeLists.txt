cmake_minimum_required(VERSION 3.19)
project(PlanetPlayerDemo)

include(${CMAKE_CURRENT_SOURCE_DIR}/../vendor.cmake)

set(path ${CMAKE_CURRENT_SOURCE_DIR}/..)

set(CMAKE_CXX_STANDARD 14)

# 设置 SDK 的根目录
set(ProjectPath ${CMAKE_CURRENT_SOURCE_DIR}/../../PlanetPlayer)

# 自定义方法 链接 ffmpeg 库目录
link_ffmpeg_directory(${path})

# 播放器项目的头文件
set(DEMO_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src)

# SDK 提供的头文件
list(APPEND DEMO_INCLUDES ${ProjectPath}/include)

# 播放器项目的源文件
file(GLOB_RECURSE DEMO_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.*)

# 添加 SDK 的目录
add_subdirectory(${ProjectPath}/ PlanetPlayer)

# 播放器项目
add_executable(PlanetPlayerDemo ${DEMO_SOURCE_FILES})

# 包含头文件内容
target_include_directories(PlanetPlayerDemo PUBLIC ${DEMO_INCLUDES})

# 链接三方库
target_link_libraries(PlanetPlayerDemo PlanetPlayer)

# 自定义方法 链接 ffmpeg
link_ffmpeg_library(PlanetPlayerDemo ${path})