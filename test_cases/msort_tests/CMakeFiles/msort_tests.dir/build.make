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
CMAKE_SOURCE_DIR = /home/cs104/hw-liu994/hw5/hw5_tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs104/hw-liu994/hw5/hw5_tests

# Include any dependencies generated for this target.
include msort_tests/CMakeFiles/msort_tests.dir/depend.make

# Include the progress variables for this target.
include msort_tests/CMakeFiles/msort_tests.dir/progress.make

# Include the compile flags for this target's objects.
include msort_tests/CMakeFiles/msort_tests.dir/flags.make

msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o: msort_tests/CMakeFiles/msort_tests.dir/flags.make
msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o: msort_tests/msort_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs104/hw-liu994/hw5/hw5_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o"
	cd /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/msort_tests.dir/msort_tests.cpp.o -c /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests/msort_tests.cpp

msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/msort_tests.dir/msort_tests.cpp.i"
	cd /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests/msort_tests.cpp > CMakeFiles/msort_tests.dir/msort_tests.cpp.i

msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/msort_tests.dir/msort_tests.cpp.s"
	cd /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests/msort_tests.cpp -o CMakeFiles/msort_tests.dir/msort_tests.cpp.s

msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o.requires:

.PHONY : msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o.requires

msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o.provides: msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o.requires
	$(MAKE) -f msort_tests/CMakeFiles/msort_tests.dir/build.make msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o.provides.build
.PHONY : msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o.provides

msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o.provides.build: msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o


# Object files for target msort_tests
msort_tests_OBJECTS = \
"CMakeFiles/msort_tests.dir/msort_tests.cpp.o"

# External object files for target msort_tests
msort_tests_EXTERNAL_OBJECTS =

msort_tests/msort_tests: msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o
msort_tests/msort_tests: msort_tests/CMakeFiles/msort_tests.dir/build.make
msort_tests/msort_tests: testing_utils/libtesting_utils.a
msort_tests/msort_tests: /usr/lib/libgtest_main.a
msort_tests/msort_tests: /usr/lib/libgtest.a
msort_tests/msort_tests: testing_utils/kwsys/libkwsys.a
msort_tests/msort_tests: testing_utils/libperf/libperf.a
msort_tests/msort_tests: msort_tests/CMakeFiles/msort_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cs104/hw-liu994/hw5/hw5_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable msort_tests"
	cd /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/msort_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
msort_tests/CMakeFiles/msort_tests.dir/build: msort_tests/msort_tests

.PHONY : msort_tests/CMakeFiles/msort_tests.dir/build

msort_tests/CMakeFiles/msort_tests.dir/requires: msort_tests/CMakeFiles/msort_tests.dir/msort_tests.cpp.o.requires

.PHONY : msort_tests/CMakeFiles/msort_tests.dir/requires

msort_tests/CMakeFiles/msort_tests.dir/clean:
	cd /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests && $(CMAKE_COMMAND) -P CMakeFiles/msort_tests.dir/cmake_clean.cmake
.PHONY : msort_tests/CMakeFiles/msort_tests.dir/clean

msort_tests/CMakeFiles/msort_tests.dir/depend:
	cd /home/cs104/hw-liu994/hw5/hw5_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs104/hw-liu994/hw5/hw5_tests /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests /home/cs104/hw-liu994/hw5/hw5_tests /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests/CMakeFiles/msort_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : msort_tests/CMakeFiles/msort_tests.dir/depend

