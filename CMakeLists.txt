cmake_minimum_required(VERSION 3.19)
project(PlanetPlayer)

set(CMAKE_CXX_STANDARD 14)

# SDK 的头文件
set(PLANET_INCLUDES ./ include src)

include(${CMAKE_CURRENT_SOURCE_DIR}/config.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/vendor.cmake)

# 添加三方库头文件的依赖
list(APPEND PLANET_INCLUDES ${ffmpeg_dir}/include)
list(APPEND PLANET_INCLUDES ${spdlog_dir}/include)
link_ffmpeg_directory()

# SDK 的源文件
file(GLOB_RECURSE PLANET_FILES
        src/*.* mp4parser/src/*.*)

# 编译 SDK 的静态库
add_library(PlanetPlayer STATIC ${PLANET_FILES})

# 包含头文件内容
target_include_directories(PlanetPlayer PUBLIC ${PLANET_INCLUDES})

# 链接三方库
target_link_libraries(PlanetPlayer gtest)

# 链接 ffmpeg
link_ffmpeg_library(PlanetPlayer)
link_spdlog_library(PlanetPlayer)

##########################################################

add_subdirectory(./3rdparty/googletest)

file(GLOB_RECURSE PLANET_TEST_FILES
        test/src/*.*
        test/src/ffmpeg_test/*.*
        test/src/utils/*.*)

set(PLANET_TEST_INCLUDES 3rdparty/googletest/googletest 3rdparty/googletest/googletest/include
        3rdparty/googletest/googlemock/include)

list(APPEND PLANET_TEST_INCLUDES ${PLANET_INCLUDES})

add_executable(PlanetUnitTest ${PLANET_TEST_FILES})
target_include_directories(PlanetUnitTest PUBLIC ${PLANET_TEST_INCLUDES})
target_link_libraries(PlanetUnitTest PlanetPlayer gtest)
set_target_properties(PlanetUnitTest PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -fno-access-control")

