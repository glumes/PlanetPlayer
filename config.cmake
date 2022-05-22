# 设置当前工程的路径，替换成自己的
set(project_dir /Users/jelin/OpenSourceCode/PlanetPlayer)

# 设置第三方库文件夹路径，替换成自己的
set(3rdparty_dir /Users/jelin/OpenSourceCode/PlanetPlayer/3rdparty)

# 设置 mac 上 ffmpeg 的安装路径
if (CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
    set(ffmpeg_dir /usr/local/Cellar/ffmpeg/5.0.1)
elseif (CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "arm64")
    set(ffmpeg_dir /opt/homebrew/Cellar/ffmpeg/5.0.1)
endif ()

add_definitions(-DPROJECT_DIR_PATH="${project_dir}")

set(spdlog_dir ${3rdparty_dir}/spdlog)
add_subdirectory(${spdlog_dir})
