cmake_minimum_required(VERSION 3.24.3 FATAL_ERROR)

project(Rotate_Image)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Rotate_Image src/main.cpp)

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )