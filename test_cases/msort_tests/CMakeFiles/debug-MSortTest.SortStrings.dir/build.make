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

# Utility rule file for debug-MSortTest.SortStrings.

# Include the progress variables for this target.
include msort_tests/CMakeFiles/debug-MSortTest.SortStrings.dir/progress.make

msort_tests/CMakeFiles/debug-MSortTest.SortStrings:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cs104/hw-liu994/hw5/hw5_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Debugging MSortTest.SortStrings with GDB..."
	cd /home/cs104/hw-liu994/hw5 && gdb --args /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests/msort_tests --gtest_filter=MSortTest.SortStrings

debug-MSortTest.SortStrings: msort_tests/CMakeFiles/debug-MSortTest.SortStrings
debug-MSortTest.SortStrings: msort_tests/CMakeFiles/debug-MSortTest.SortStrings.dir/build.make

.PHONY : debug-MSortTest.SortStrings

# Rule to build all files generated by this target.
msort_tests/CMakeFiles/debug-MSortTest.SortStrings.dir/build: debug-MSortTest.SortStrings

.PHONY : msort_tests/CMakeFiles/debug-MSortTest.SortStrings.dir/build

msort_tests/CMakeFiles/debug-MSortTest.SortStrings.dir/clean:
	cd /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests && $(CMAKE_COMMAND) -P CMakeFiles/debug-MSortTest.SortStrings.dir/cmake_clean.cmake
.PHONY : msort_tests/CMakeFiles/debug-MSortTest.SortStrings.dir/clean

msort_tests/CMakeFiles/debug-MSortTest.SortStrings.dir/depend:
	cd /home/cs104/hw-liu994/hw5/hw5_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs104/hw-liu994/hw5/hw5_tests /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests /home/cs104/hw-liu994/hw5/hw5_tests /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests /home/cs104/hw-liu994/hw5/hw5_tests/msort_tests/CMakeFiles/debug-MSortTest.SortStrings.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : msort_tests/CMakeFiles/debug-MSortTest.SortStrings.dir/depend

