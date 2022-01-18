<<<<<<< HEAD
# CMake Minimum version requirements
cmake_minimum_required (VERSION 2.8)

# Project information
project (Demo2)

#Find all source files in the current directory
#And save the name to dir_ SRCs variable
aux_source_directory(. DIR_SRCS)

# Specify build target
add_executable(Demo ${DIR_SRCS})

=======
# CMake Minimum version requirements
cmake_minimum_required (VERSION 2.8)

# Project information
project (Demo2)

#Find all source files in the current directory
#And save the name to dir_ SRCs variable
aux_source_directory(. DIR_SRCS)

# Specify build target
add_executable(Demo ${DIR_SRCS})

>>>>>>> 1d751b2d5d0f314aae5ee85cadda02a076b13d0f
