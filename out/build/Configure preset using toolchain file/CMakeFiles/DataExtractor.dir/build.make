# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Volumes/Data/Projects/C++/DataExtractor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/Data/Projects/C++/DataExtractor/out/build/Configure preset using toolchain file"

# Include any dependencies generated for this target.
include CMakeFiles/DataExtractor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DataExtractor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DataExtractor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataExtractor.dir/flags.make

CMakeFiles/DataExtractor.dir/src/main.cpp.o: CMakeFiles/DataExtractor.dir/flags.make
CMakeFiles/DataExtractor.dir/src/main.cpp.o: /Volumes/Data/Projects/C++/DataExtractor/src/main.cpp
CMakeFiles/DataExtractor.dir/src/main.cpp.o: CMakeFiles/DataExtractor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Volumes/Data/Projects/C++/DataExtractor/out/build/Configure preset using toolchain file/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataExtractor.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DataExtractor.dir/src/main.cpp.o -MF CMakeFiles/DataExtractor.dir/src/main.cpp.o.d -o CMakeFiles/DataExtractor.dir/src/main.cpp.o -c /Volumes/Data/Projects/C++/DataExtractor/src/main.cpp

CMakeFiles/DataExtractor.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DataExtractor.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Volumes/Data/Projects/C++/DataExtractor/src/main.cpp > CMakeFiles/DataExtractor.dir/src/main.cpp.i

CMakeFiles/DataExtractor.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DataExtractor.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Volumes/Data/Projects/C++/DataExtractor/src/main.cpp -o CMakeFiles/DataExtractor.dir/src/main.cpp.s

# Object files for target DataExtractor
DataExtractor_OBJECTS = \
"CMakeFiles/DataExtractor.dir/src/main.cpp.o"

# External object files for target DataExtractor
DataExtractor_EXTERNAL_OBJECTS =

DataExtractor: CMakeFiles/DataExtractor.dir/src/main.cpp.o
DataExtractor: CMakeFiles/DataExtractor.dir/build.make
DataExtractor: /opt/homebrew/lib/libssl.dylib
DataExtractor: /opt/homebrew/lib/libcrypto.dylib
DataExtractor: CMakeFiles/DataExtractor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Volumes/Data/Projects/C++/DataExtractor/out/build/Configure preset using toolchain file/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DataExtractor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataExtractor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataExtractor.dir/build: DataExtractor
.PHONY : CMakeFiles/DataExtractor.dir/build

CMakeFiles/DataExtractor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataExtractor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataExtractor.dir/clean

CMakeFiles/DataExtractor.dir/depend:
	cd "/Volumes/Data/Projects/C++/DataExtractor/out/build/Configure preset using toolchain file" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/Data/Projects/C++/DataExtractor /Volumes/Data/Projects/C++/DataExtractor "/Volumes/Data/Projects/C++/DataExtractor/out/build/Configure preset using toolchain file" "/Volumes/Data/Projects/C++/DataExtractor/out/build/Configure preset using toolchain file" "/Volumes/Data/Projects/C++/DataExtractor/out/build/Configure preset using toolchain file/CMakeFiles/DataExtractor.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/DataExtractor.dir/depend

