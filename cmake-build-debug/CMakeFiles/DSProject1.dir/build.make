# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/michel/CLionProjects/DSProject1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/michel/CLionProjects/DSProject1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DSProject1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DSProject1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DSProject1.dir/flags.make

CMakeFiles/DSProject1.dir/main.cpp.o: CMakeFiles/DSProject1.dir/flags.make
CMakeFiles/DSProject1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/michel/CLionProjects/DSProject1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DSProject1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DSProject1.dir/main.cpp.o -c /Users/michel/CLionProjects/DSProject1/main.cpp

CMakeFiles/DSProject1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DSProject1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/michel/CLionProjects/DSProject1/main.cpp > CMakeFiles/DSProject1.dir/main.cpp.i

CMakeFiles/DSProject1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DSProject1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/michel/CLionProjects/DSProject1/main.cpp -o CMakeFiles/DSProject1.dir/main.cpp.s

# Object files for target DSProject1
DSProject1_OBJECTS = \
"CMakeFiles/DSProject1.dir/main.cpp.o"

# External object files for target DSProject1
DSProject1_EXTERNAL_OBJECTS =

DSProject1: CMakeFiles/DSProject1.dir/main.cpp.o
DSProject1: CMakeFiles/DSProject1.dir/build.make
DSProject1: CMakeFiles/DSProject1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/michel/CLionProjects/DSProject1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DSProject1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DSProject1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DSProject1.dir/build: DSProject1

.PHONY : CMakeFiles/DSProject1.dir/build

CMakeFiles/DSProject1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DSProject1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DSProject1.dir/clean

CMakeFiles/DSProject1.dir/depend:
	cd /Users/michel/CLionProjects/DSProject1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/michel/CLionProjects/DSProject1 /Users/michel/CLionProjects/DSProject1 /Users/michel/CLionProjects/DSProject1/cmake-build-debug /Users/michel/CLionProjects/DSProject1/cmake-build-debug /Users/michel/CLionProjects/DSProject1/cmake-build-debug/CMakeFiles/DSProject1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DSProject1.dir/depend

