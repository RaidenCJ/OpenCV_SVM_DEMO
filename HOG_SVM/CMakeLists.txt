cmake_minimum_required(VERSION 2.8)
project(HOG_SVM)
 
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/) 

find_package(OpenCV REQUIRED)
 
include_directories(. ${OpenCV_INCLUDE_DIRS})

add_executable(HOG_SVM
               hog_svm.cpp
               )
target_link_libraries(HOG_SVM ${OpenCV_LIBS})