
file(GLOB_RECURSE src RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h)

add_executable (Application ${src})
TARGET_LINK_LIBRARIES(Application ${OpenCV_LIBS})
