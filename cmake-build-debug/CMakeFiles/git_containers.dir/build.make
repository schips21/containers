# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tatiana/Desktop/git_cont

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tatiana/Desktop/git_cont/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/git_containers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/git_containers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/git_containers.dir/flags.make

CMakeFiles/git_containers.dir/main.cpp.o: CMakeFiles/git_containers.dir/flags.make
CMakeFiles/git_containers.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tatiana/Desktop/git_cont/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/git_containers.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/git_containers.dir/main.cpp.o -c /Users/tatiana/Desktop/git_cont/main.cpp

CMakeFiles/git_containers.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/git_containers.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tatiana/Desktop/git_cont/main.cpp > CMakeFiles/git_containers.dir/main.cpp.i

CMakeFiles/git_containers.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/git_containers.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tatiana/Desktop/git_cont/main.cpp -o CMakeFiles/git_containers.dir/main.cpp.s

# Object files for target git_containers
git_containers_OBJECTS = \
"CMakeFiles/git_containers.dir/main.cpp.o"

# External object files for target git_containers
git_containers_EXTERNAL_OBJECTS =

git_containers: CMakeFiles/git_containers.dir/main.cpp.o
git_containers: CMakeFiles/git_containers.dir/build.make
git_containers: CMakeFiles/git_containers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tatiana/Desktop/git_cont/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable git_containers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/git_containers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/git_containers.dir/build: git_containers

.PHONY : CMakeFiles/git_containers.dir/build

CMakeFiles/git_containers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/git_containers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/git_containers.dir/clean

CMakeFiles/git_containers.dir/depend:
	cd /Users/tatiana/Desktop/git_cont/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tatiana/Desktop/git_cont /Users/tatiana/Desktop/git_cont /Users/tatiana/Desktop/git_cont/cmake-build-debug /Users/tatiana/Desktop/git_cont/cmake-build-debug /Users/tatiana/Desktop/git_cont/cmake-build-debug/CMakeFiles/git_containers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/git_containers.dir/depend

