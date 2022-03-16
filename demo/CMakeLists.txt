cmake_minimum_required(VERSION 3.19)
project(PlanetPlayerDemo)

include(${CMAKE_CURRENT_SOURCE_DIR}/../vendor.cmake)

set(path ${CMAKE_CURRENT_SOURCE_DIR}/..)

set(CMAKE_CXX_STANDARD 14)

set(ProjectPath ${CMAKE_CURRENT_SOURCE_DIR}/../../PlanetPlayer)

link_ffmpeg_directory(${path})

set(DEMO_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/src)

list(APPEND DEMO_INCLUDES ${ProjectPath}/include)

file(GLOB_RECURSE DEMO_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.*)

add_subdirectory(${ProjectPath}/ PlanetPlayer)

add_executable(PlanetPlayerDemo ${DEMO_SOURCE_FILES})
target_include_directories(PlanetPlayerDemo PUBLIC ${DEMO_INCLUDES})
target_link_libraries(PlanetPlayerDemo PlanetPlayer)
link_ffmpeg_library(PlanetPlayerDemo ${path})