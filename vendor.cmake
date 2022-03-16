message(STATUS "operation system is ${CMAKE_SYSTEM}")

if (CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64")
    set(arch arm64)
elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
    set(arch x64)
endif ()

if (WIN32)
    set(platform win)
elseif (APPLE)
    set(platform mac)
else ()
    message(FATAL_ERROR "not support current platform")
endif ()

function(link_ffmpeg_directory path)
    link_directories(${path}/lib/ffmpeg/${platform}/${arch}/lib)
endfunction()

function(link_ffmpeg_library target path)
    target_link_libraries(${target} avcodec avdevice avfilter avformat avutil postproc swresample swscale)
endfunction()