#cmake 最低版本要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project(renderer)

# 
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(OpenGL REQUIRED)
# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb -g3 -std=c++11")
set(HEAD_FILES
  ./src/mainWidget.h ./src/enThread.h
)

#set(ALL_FORMS ...)

set(SRC_FILES ./src/main.cpp ./src/mainWidget.cpp ./src/enThread.cpp)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
#QT5_WRAP_CPP(HEAD_MOC $(ALL_HEADERS))
#QT5_WRAP_UI(FORMS_HEADERS $(ALL_FORMS) )
#QT5_ADD_RESOURCES(RESOURCES_RCC $(ALL_RESOURCES))
include_directories($(CMAKE_CURRENT_BINARY_DIR))


# 指定生成目标
add_executable(renderer ${HEAD_FILES} ${SRC_FILES})
#add_executable(renderer ./src/main.cpp ./src/opengl_thread.cpp ./src/opengl_thread.h
#  ./src/opengl_widget.cpp ./src/opengl_widget.h)

set(3rdParty_LIBRARIES ${QPENGL_LIBRARIES} libOpenGL.so)

target_link_libraries(renderer ${3rdParty_LIBRARIES} Qt5::Widgets Qt5::OpenGL)
# 添加子目录
#add_subdirectory(math)






