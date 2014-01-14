
file(GLOB_RECURSE src RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable (Application ${src})
TARGET_LINK_LIBRARIES(Application ${OpenCV_LIBS})
