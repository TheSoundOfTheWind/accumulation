#cmake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目信息
project(qglwidget-multithread)

#查找当前目录下的所有源文件
#并将名称保存到DIR_SRCS变量中
aux_source_directory(./src DIR_SRCS)

#生成链接库
#add_library (mathfunctions ${DIR_SRCS})

# 指定生成目标
add_executable(qglwidget-multithread ${DIR_SRCS})

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD True)

# 添加子目录
#add_subdirectory(math)






