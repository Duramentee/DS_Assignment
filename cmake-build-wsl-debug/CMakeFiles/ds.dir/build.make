# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kojimamemes/DS_Assignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kojimamemes/DS_Assignment/cmake-build-wsl-debug

# Include any dependencies generated for this target.
include CMakeFiles/ds.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ds.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ds.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ds.dir/flags.make

CMakeFiles/ds.dir/main.cpp.o: CMakeFiles/ds.dir/flags.make
CMakeFiles/ds.dir/main.cpp.o: /home/kojimamemes/DS_Assignment/main.cpp
CMakeFiles/ds.dir/main.cpp.o: CMakeFiles/ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kojimamemes/DS_Assignment/cmake-build-wsl-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ds.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ds.dir/main.cpp.o -MF CMakeFiles/ds.dir/main.cpp.o.d -o CMakeFiles/ds.dir/main.cpp.o -c /home/kojimamemes/DS_Assignment/main.cpp

CMakeFiles/ds.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ds.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kojimamemes/DS_Assignment/main.cpp > CMakeFiles/ds.dir/main.cpp.i

CMakeFiles/ds.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ds.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kojimamemes/DS_Assignment/main.cpp -o CMakeFiles/ds.dir/main.cpp.s

# Object files for target ds
ds_OBJECTS = \
"CMakeFiles/ds.dir/main.cpp.o"

# External object files for target ds
ds_EXTERNAL_OBJECTS =

ds: CMakeFiles/ds.dir/main.cpp.o
ds: CMakeFiles/ds.dir/build.make
ds: CMakeFiles/ds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kojimamemes/DS_Assignment/cmake-build-wsl-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ds"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ds.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ds.dir/build: ds
.PHONY : CMakeFiles/ds.dir/build

CMakeFiles/ds.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ds.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ds.dir/clean

CMakeFiles/ds.dir/depend:
	cd /home/kojimamemes/DS_Assignment/cmake-build-wsl-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kojimamemes/DS_Assignment /home/kojimamemes/DS_Assignment /home/kojimamemes/DS_Assignment/cmake-build-wsl-debug /home/kojimamemes/DS_Assignment/cmake-build-wsl-debug /home/kojimamemes/DS_Assignment/cmake-build-wsl-debug/CMakeFiles/ds.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ds.dir/depend

