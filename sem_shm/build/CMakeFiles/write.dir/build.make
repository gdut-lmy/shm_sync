# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /home/lmy/.local/lib/python3.6/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/lmy/.local/lib/python3.6/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lmy/processThread/sem_shm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lmy/processThread/sem_shm/build

# Include any dependencies generated for this target.
include CMakeFiles/write.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/write.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/write.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/write.dir/flags.make

CMakeFiles/write.dir/write.cpp.o: CMakeFiles/write.dir/flags.make
CMakeFiles/write.dir/write.cpp.o: ../write.cpp
CMakeFiles/write.dir/write.cpp.o: CMakeFiles/write.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmy/processThread/sem_shm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/write.dir/write.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/write.dir/write.cpp.o -MF CMakeFiles/write.dir/write.cpp.o.d -o CMakeFiles/write.dir/write.cpp.o -c /home/lmy/processThread/sem_shm/write.cpp

CMakeFiles/write.dir/write.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/write.dir/write.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmy/processThread/sem_shm/write.cpp > CMakeFiles/write.dir/write.cpp.i

CMakeFiles/write.dir/write.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/write.dir/write.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmy/processThread/sem_shm/write.cpp -o CMakeFiles/write.dir/write.cpp.s

# Object files for target write
write_OBJECTS = \
"CMakeFiles/write.dir/write.cpp.o"

# External object files for target write
write_EXTERNAL_OBJECTS =

write: CMakeFiles/write.dir/write.cpp.o
write: CMakeFiles/write.dir/build.make
write: CMakeFiles/write.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lmy/processThread/sem_shm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable write"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/write.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/write.dir/build: write
.PHONY : CMakeFiles/write.dir/build

CMakeFiles/write.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/write.dir/cmake_clean.cmake
.PHONY : CMakeFiles/write.dir/clean

CMakeFiles/write.dir/depend:
	cd /home/lmy/processThread/sem_shm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lmy/processThread/sem_shm /home/lmy/processThread/sem_shm /home/lmy/processThread/sem_shm/build /home/lmy/processThread/sem_shm/build /home/lmy/processThread/sem_shm/build/CMakeFiles/write.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/write.dir/depend

