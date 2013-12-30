
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

FIND_PACKAGE(OpenCV REQUIRED)



file(GLOB_RECURSE src RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h)

project(OpenCVLaboratory)

add_executable (OpenCVLaboratory ${src})
TARGET_LINK_LIBRARIES(OpenCVLaboratory ${OpenCV_LIBS})


