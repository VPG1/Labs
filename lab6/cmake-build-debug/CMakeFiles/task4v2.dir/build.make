# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Clion\labs\lab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Clion\labs\lab6\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task4v2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/task4v2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task4v2.dir/flags.make

CMakeFiles/task4v2.dir/task4v2.cpp.obj: CMakeFiles/task4v2.dir/flags.make
CMakeFiles/task4v2.dir/task4v2.cpp.obj: ../task4v2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Clion\labs\lab6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task4v2.dir/task4v2.cpp.obj"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\task4v2.dir\task4v2.cpp.obj -c C:\Clion\labs\lab6\task4v2.cpp

CMakeFiles/task4v2.dir/task4v2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task4v2.dir/task4v2.cpp.i"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Clion\labs\lab6\task4v2.cpp > CMakeFiles\task4v2.dir\task4v2.cpp.i

CMakeFiles/task4v2.dir/task4v2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task4v2.dir/task4v2.cpp.s"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Clion\labs\lab6\task4v2.cpp -o CMakeFiles\task4v2.dir\task4v2.cpp.s

# Object files for target task4v2
task4v2_OBJECTS = \
"CMakeFiles/task4v2.dir/task4v2.cpp.obj"

# External object files for target task4v2
task4v2_EXTERNAL_OBJECTS =

task4v2.exe: CMakeFiles/task4v2.dir/task4v2.cpp.obj
task4v2.exe: CMakeFiles/task4v2.dir/build.make
task4v2.exe: CMakeFiles/task4v2.dir/linklibs.rsp
task4v2.exe: CMakeFiles/task4v2.dir/objects1.rsp
task4v2.exe: CMakeFiles/task4v2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Clion\labs\lab6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task4v2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\task4v2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task4v2.dir/build: task4v2.exe
.PHONY : CMakeFiles/task4v2.dir/build

CMakeFiles/task4v2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\task4v2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/task4v2.dir/clean

CMakeFiles/task4v2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Clion\labs\lab6 C:\Clion\labs\lab6 C:\Clion\labs\lab6\cmake-build-debug C:\Clion\labs\lab6\cmake-build-debug C:\Clion\labs\lab6\cmake-build-debug\CMakeFiles\task4v2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task4v2.dir/depend

