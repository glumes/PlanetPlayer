# 链接 ffmpeg 库的目录
function(link_ffmpeg_directory)
link_directories(${ffmpeg_dir}/lib/)
endfunction()

# 链接 ffmpeg 中的库
function(link_ffmpeg_library target)
target_link_libraries(${target}
        avformat
        avcodec
        avdevice
        avfilter
        avutil
        postproc
        swresample
        swscale
        )
endfunction()

function(link_spdlog_library target)
target_link_libraries(${target} spdlog)
endfunction()