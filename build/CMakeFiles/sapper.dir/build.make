# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ivan/Documents/GitHub/sapper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ivan/Documents/GitHub/sapper/build

# Include any dependencies generated for this target.
include CMakeFiles/sapper.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sapper.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sapper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sapper.dir/flags.make

CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.o: CMakeFiles/sapper.dir/flags.make
CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.o: /Users/ivan/Documents/GitHub/sapper/lib/vec/vec2d.cpp
CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.o: CMakeFiles/sapper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivan/Documents/GitHub/sapper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.o -MF CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.o.d -o CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.o -c /Users/ivan/Documents/GitHub/sapper/lib/vec/vec2d.cpp

CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivan/Documents/GitHub/sapper/lib/vec/vec2d.cpp > CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.i

CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivan/Documents/GitHub/sapper/lib/vec/vec2d.cpp -o CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.s

CMakeFiles/sapper.dir/lib/table/bombs.cpp.o: CMakeFiles/sapper.dir/flags.make
CMakeFiles/sapper.dir/lib/table/bombs.cpp.o: /Users/ivan/Documents/GitHub/sapper/lib/table/bombs.cpp
CMakeFiles/sapper.dir/lib/table/bombs.cpp.o: CMakeFiles/sapper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivan/Documents/GitHub/sapper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sapper.dir/lib/table/bombs.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sapper.dir/lib/table/bombs.cpp.o -MF CMakeFiles/sapper.dir/lib/table/bombs.cpp.o.d -o CMakeFiles/sapper.dir/lib/table/bombs.cpp.o -c /Users/ivan/Documents/GitHub/sapper/lib/table/bombs.cpp

CMakeFiles/sapper.dir/lib/table/bombs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sapper.dir/lib/table/bombs.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivan/Documents/GitHub/sapper/lib/table/bombs.cpp > CMakeFiles/sapper.dir/lib/table/bombs.cpp.i

CMakeFiles/sapper.dir/lib/table/bombs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sapper.dir/lib/table/bombs.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivan/Documents/GitHub/sapper/lib/table/bombs.cpp -o CMakeFiles/sapper.dir/lib/table/bombs.cpp.s

CMakeFiles/sapper.dir/lib/table/table.cpp.o: CMakeFiles/sapper.dir/flags.make
CMakeFiles/sapper.dir/lib/table/table.cpp.o: /Users/ivan/Documents/GitHub/sapper/lib/table/table.cpp
CMakeFiles/sapper.dir/lib/table/table.cpp.o: CMakeFiles/sapper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivan/Documents/GitHub/sapper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sapper.dir/lib/table/table.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sapper.dir/lib/table/table.cpp.o -MF CMakeFiles/sapper.dir/lib/table/table.cpp.o.d -o CMakeFiles/sapper.dir/lib/table/table.cpp.o -c /Users/ivan/Documents/GitHub/sapper/lib/table/table.cpp

CMakeFiles/sapper.dir/lib/table/table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sapper.dir/lib/table/table.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivan/Documents/GitHub/sapper/lib/table/table.cpp > CMakeFiles/sapper.dir/lib/table/table.cpp.i

CMakeFiles/sapper.dir/lib/table/table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sapper.dir/lib/table/table.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivan/Documents/GitHub/sapper/lib/table/table.cpp -o CMakeFiles/sapper.dir/lib/table/table.cpp.s

CMakeFiles/sapper.dir/src/main.cpp.o: CMakeFiles/sapper.dir/flags.make
CMakeFiles/sapper.dir/src/main.cpp.o: /Users/ivan/Documents/GitHub/sapper/src/main.cpp
CMakeFiles/sapper.dir/src/main.cpp.o: CMakeFiles/sapper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivan/Documents/GitHub/sapper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sapper.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sapper.dir/src/main.cpp.o -MF CMakeFiles/sapper.dir/src/main.cpp.o.d -o CMakeFiles/sapper.dir/src/main.cpp.o -c /Users/ivan/Documents/GitHub/sapper/src/main.cpp

CMakeFiles/sapper.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sapper.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivan/Documents/GitHub/sapper/src/main.cpp > CMakeFiles/sapper.dir/src/main.cpp.i

CMakeFiles/sapper.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sapper.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivan/Documents/GitHub/sapper/src/main.cpp -o CMakeFiles/sapper.dir/src/main.cpp.s

# Object files for target sapper
sapper_OBJECTS = \
"CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.o" \
"CMakeFiles/sapper.dir/lib/table/bombs.cpp.o" \
"CMakeFiles/sapper.dir/lib/table/table.cpp.o" \
"CMakeFiles/sapper.dir/src/main.cpp.o"

# External object files for target sapper
sapper_EXTERNAL_OBJECTS =

sapper: CMakeFiles/sapper.dir/lib/vec/vec2d.cpp.o
sapper: CMakeFiles/sapper.dir/lib/table/bombs.cpp.o
sapper: CMakeFiles/sapper.dir/lib/table/table.cpp.o
sapper: CMakeFiles/sapper.dir/src/main.cpp.o
sapper: CMakeFiles/sapper.dir/build.make
sapper: /opt/homebrew/lib/libfltk_images.dylib
sapper: /opt/homebrew/lib/libfltk_forms.dylib
sapper: /opt/homebrew/lib/libfltk_gl.dylib
sapper: /opt/homebrew/lib/libfltk.dylib
sapper: CMakeFiles/sapper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ivan/Documents/GitHub/sapper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable sapper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sapper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sapper.dir/build: sapper
.PHONY : CMakeFiles/sapper.dir/build

CMakeFiles/sapper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sapper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sapper.dir/clean

CMakeFiles/sapper.dir/depend:
	cd /Users/ivan/Documents/GitHub/sapper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivan/Documents/GitHub/sapper /Users/ivan/Documents/GitHub/sapper /Users/ivan/Documents/GitHub/sapper/build /Users/ivan/Documents/GitHub/sapper/build /Users/ivan/Documents/GitHub/sapper/build/CMakeFiles/sapper.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sapper.dir/depend
