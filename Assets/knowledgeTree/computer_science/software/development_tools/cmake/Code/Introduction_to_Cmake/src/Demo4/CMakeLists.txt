# CMake Minimum version requirements
cmake_minimum_required (VERSION 2.8)

# Project information
project (Demo4)

# 

#Find all source files in the current directory
#And save the name to dir_ SRCs variable
aux_source_directory(. DIR_SRCS)

# Add math subdirectory
add_subdirectory(math)

# Specify header file path
include_directories(math)

# Specify build target
add_executable(Demo main.cc)

#Add link library
target_link_libraries(Demo MathFunctions)

