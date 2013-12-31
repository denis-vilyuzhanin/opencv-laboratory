
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

FIND_PACKAGE(OpenCV REQUIRED)

project(OpenCVLaboratory)

add_subdirectory(src)
