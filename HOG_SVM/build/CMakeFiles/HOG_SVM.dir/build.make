# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM/build

# Include any dependencies generated for this target.
include CMakeFiles/HOG_SVM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HOG_SVM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HOG_SVM.dir/flags.make

CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o: CMakeFiles/HOG_SVM.dir/flags.make
CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o: ../hog_svm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o -c /home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM/hog_svm.cpp

CMakeFiles/HOG_SVM.dir/hog_svm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HOG_SVM.dir/hog_svm.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM/hog_svm.cpp > CMakeFiles/HOG_SVM.dir/hog_svm.cpp.i

CMakeFiles/HOG_SVM.dir/hog_svm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HOG_SVM.dir/hog_svm.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM/hog_svm.cpp -o CMakeFiles/HOG_SVM.dir/hog_svm.cpp.s

CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o.requires:

.PHONY : CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o.requires

CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o.provides: CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o.requires
	$(MAKE) -f CMakeFiles/HOG_SVM.dir/build.make CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o.provides.build
.PHONY : CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o.provides

CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o.provides.build: CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o


# Object files for target HOG_SVM
HOG_SVM_OBJECTS = \
"CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o"

# External object files for target HOG_SVM
HOG_SVM_EXTERNAL_OBJECTS =

../HOG_SVM: CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o
../HOG_SVM: CMakeFiles/HOG_SVM.dir/build.make
../HOG_SVM: /usr/local/lib/libopencv_stitching.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_superres.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_videostab.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_aruco.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_bgsegm.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_bioinspired.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_ccalib.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_cvv.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_dpm.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_face.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_freetype.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_fuzzy.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_img_hash.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_line_descriptor.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_optflow.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_reg.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_rgbd.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_saliency.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_stereo.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_structured_light.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_surface_matching.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_tracking.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_xfeatures2d.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_ximgproc.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_xobjdetect.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_xphoto.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_shape.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_photo.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_calib3d.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_phase_unwrapping.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_dnn.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_video.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_datasets.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_plot.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_text.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_features2d.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_flann.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_highgui.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_ml.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_videoio.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_imgcodecs.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_objdetect.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_imgproc.so.3.3.0
../HOG_SVM: /usr/local/lib/libopencv_core.so.3.3.0
../HOG_SVM: CMakeFiles/HOG_SVM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../HOG_SVM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HOG_SVM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HOG_SVM.dir/build: ../HOG_SVM

.PHONY : CMakeFiles/HOG_SVM.dir/build

CMakeFiles/HOG_SVM.dir/requires: CMakeFiles/HOG_SVM.dir/hog_svm.cpp.o.requires

.PHONY : CMakeFiles/HOG_SVM.dir/requires

CMakeFiles/HOG_SVM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HOG_SVM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HOG_SVM.dir/clean

CMakeFiles/HOG_SVM.dir/depend:
	cd /home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM /home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM /home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM/build /home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM/build /home/raiden/Proj/SSV_SVM_DEMO/SSV_DEMO/HOG_SVM/build/CMakeFiles/HOG_SVM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HOG_SVM.dir/depend

