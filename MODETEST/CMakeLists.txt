cmake_minimum_required(VERSION 2.8)
project(MODETEST)
 
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/) 

find_package(OpenCV REQUIRED)
 
include_directories(. ${OpenCV_INCLUDE_DIRS})

add_executable(MODETEST
               modetest.cpp
               )
target_link_libraries(MODETEST ${OpenCV_LIBS})