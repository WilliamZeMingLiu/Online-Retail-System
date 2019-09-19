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

# Utility rule file for grade.

# Include the progress variables for this target.
include CMakeFiles/grade.dir/progress.make

CMakeFiles/grade:
	/usr/bin/cmake -E echo --\ Cleaning\ build\ dir\ to\ get\ a\ clean\ record\ of\ compilation\ warnings\ and\ errors
	make clean
	/usr/bin/cmake -E echo --\ Compiling\ testing\ tools
	make testing_utils
	/usr/bin/cmake -E echo --\ Compiling\ comparators,\ output\ saved\ to\ /home/cs104/hw-liu994/hw5/hw5_tests/compile-logs/comparators.complog
	make hw5_comparators 1>/home/cs104/hw-liu994/hw5/hw5_tests/compile-logs/comparators.complog 2>&1 || true
	/usr/bin/cmake -E echo --\ Compiling\ comparators\ tests
	make comparators_tests || true
	/usr/bin/cmake -E echo --\ Compiling\ msort\ tests,\ output\ saved\ to\ /home/cs104/hw-liu994/hw5/hw5_tests/compile-logs/msort.complog
	make msort_tests 1>/home/cs104/hw-liu994/hw5/hw5_tests/compile-logs/msort.complog 2>&1 || true
	/usr/bin/cmake -E echo --\ Compiling\ msort\ runtime\ tests
	make msort_runtime_tests || true
	/usr/bin/cmake -E echo --\ Compiling\ amazon\ using\ Makefile,\ output\ saved\ to\ /home/cs104/hw-liu994/hw5/hw5_tests/compile-logs/amazon.complog
	make run_make_amazon 1>/home/cs104/hw-liu994/hw5/hw5_tests/compile-logs/amazon.complog 2>&1 || true
	/usr/bin/cmake -E echo --\ Compiling\ amazon\ tests
	make amazon_tests || true
	/usr/bin/cmake -E remove_directory /home/cs104/hw-liu994/hw5/hw5_tests/Testing
	/usr/bin/ctest -T Test --no-compress-output -C Debug --timeout 30 || true
	/usr/bin/cmake -E echo --\ Generating\ grade\ report
	python3 /home/cs104/hw-liu994/hw5/hw5_tests/gen_grade_report.py

grade: CMakeFiles/grade
grade: CMakeFiles/grade.dir/build.make

.PHONY : grade

# Rule to build all files generated by this target.
CMakeFiles/grade.dir/build: grade

.PHONY : CMakeFiles/grade.dir/build

CMakeFiles/grade.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/grade.dir/cmake_clean.cmake
.PHONY : CMakeFiles/grade.dir/clean

CMakeFiles/grade.dir/depend:
	cd /home/cs104/hw-liu994/hw5/hw5_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs104/hw-liu994/hw5/hw5_tests /home/cs104/hw-liu994/hw5/hw5_tests /home/cs104/hw-liu994/hw5/hw5_tests /home/cs104/hw-liu994/hw5/hw5_tests /home/cs104/hw-liu994/hw5/hw5_tests/CMakeFiles/grade.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/grade.dir/depend

