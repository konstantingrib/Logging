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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kg/Git/Logging

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kg/Git/Logging

# Include any dependencies generated for this target.
include CMakeFiles/Logging.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Logging.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Logging.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Logging.dir/flags.make

CMakeFiles/Logging.dir/main.cpp.o: CMakeFiles/Logging.dir/flags.make
CMakeFiles/Logging.dir/main.cpp.o: main.cpp
CMakeFiles/Logging.dir/main.cpp.o: CMakeFiles/Logging.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kg/Git/Logging/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Logging.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Logging.dir/main.cpp.o -MF CMakeFiles/Logging.dir/main.cpp.o.d -o CMakeFiles/Logging.dir/main.cpp.o -c /home/kg/Git/Logging/main.cpp

CMakeFiles/Logging.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Logging.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kg/Git/Logging/main.cpp > CMakeFiles/Logging.dir/main.cpp.i

CMakeFiles/Logging.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Logging.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kg/Git/Logging/main.cpp -o CMakeFiles/Logging.dir/main.cpp.s

# Object files for target Logging
Logging_OBJECTS = \
"CMakeFiles/Logging.dir/main.cpp.o"

# External object files for target Logging
Logging_EXTERNAL_OBJECTS =

Logging: CMakeFiles/Logging.dir/main.cpp.o
Logging: CMakeFiles/Logging.dir/build.make
Logging: CMakeFiles/Logging.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kg/Git/Logging/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Logging"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Logging.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Logging.dir/build: Logging
.PHONY : CMakeFiles/Logging.dir/build

CMakeFiles/Logging.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Logging.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Logging.dir/clean

CMakeFiles/Logging.dir/depend:
	cd /home/kg/Git/Logging && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kg/Git/Logging /home/kg/Git/Logging /home/kg/Git/Logging /home/kg/Git/Logging /home/kg/Git/Logging/CMakeFiles/Logging.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Logging.dir/depend

