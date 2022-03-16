cmake_minimum_required(VERSION 3.19)
project(PlanetPlayer)

set(CMAKE_CXX_STANDARD 14)

set(path ${CMAKE_CURRENT_SOURCE_DIR})

# SDK 的头文件
set(PLANET_INCLUDES ./ include src)

include(${CMAKE_CURRENT_SOURCE_DIR}/vendor.cmake)

# 模拟第三方库依赖
add_subdirectory(3rdparty/test1)
list(APPEND PLANET_INCLUDES 3rdparty/test1/src)

add_subdirectory(3rdparty/test2)
list(APPEND PLANET_INCLUDES 3rdparty/test2/src)

# 添加 FFmpeg 库的依赖
list(APPEND PLANET_INCLUDES ${path}/lib/ffmpeg/${platform}/${arch}/include)
link_ffmpeg_directory(${path})

# SDK 的源文件
file(GLOB_RECURSE PLANET_FILES
        src/*.*)

# 编译 SDK 的静态库
add_library(PlanetPlayer STATIC ${PLANET_FILES})

# 包含头文件内容
target_include_directories(PlanetPlayer PUBLIC ${PLANET_INCLUDES})

# 链接三方库
target_link_libraries(PlanetPlayer  gtest TEST1 TEST2)

# 链接 ffmpeg
link_ffmpeg_library(PlanetPlayer ${path})

##########################################################

add_subdirectory(./3rdparty/googletest)

file(GLOB_RECURSE PLANET_TEST_FILES
        test/src/*.*
        test/src/utils/*.*)

set(PLANET_TEST_INCLUDES 3rdparty/googletest/googletest 3rdparty/googletest/googletest/include
        3rdparty/googletest/googlemock/include)

list(APPEND PLANET_TEST_INCLUDES ${PLANET_INCLUDES})

add_executable(PlanetUnitTest ${PLANET_TEST_FILES})
target_include_directories(PlanetUnitTest PUBLIC ${PLANET_TEST_INCLUDES})
target_link_libraries(PlanetUnitTest PlanetPlayer gtest)
set_target_properties(PlanetUnitTest PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -fno-access-control")

