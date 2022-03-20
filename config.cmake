# 设置当前工程的路径，替换成自己的
set(project_dir /Users/glumes/PlanetPlayer)

# 设置 mac 上 ffmpeg 的安装路径
set(ffmpeg_dir /opt/homebrew/Cellar/ffmpeg/5.0/)

add_definitions(-DPROJECT_DIR_PATH="${project_dir}")
