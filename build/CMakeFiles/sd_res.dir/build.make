# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build

# Include any dependencies generated for this target.
include CMakeFiles/sd_res.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sd_res.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sd_res.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sd_res.dir/flags.make

__cmrc_sd_res/lib.cpp: __cmrc_sd_res/lib_.cpp
__cmrc_sd_res/lib.cpp: _cmrc/include/cmrc/cmrc.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating sd_res resource loader"
	/opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E copy_if_different /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/__cmrc_sd_res/lib_.cpp /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/__cmrc_sd_res/lib.cpp

__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp: /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/fonts/Chalkduster.ttf
__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp: CMakeRC.cmake
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating intermediate file for /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/fonts/Chalkduster.ttf"
	/opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -D_CMRC_GENERATE_MODE=TRUE -DNAMESPACE=sd_res -DSYMBOL=f_3a24_fonts_Chalkduster_ttf -DINPUT_FILE=/Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/fonts/Chalkduster.ttf -DOUTPUT_FILE=/Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp -P /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/CMakeRC.cmake

CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.o: CMakeFiles/sd_res.dir/flags.make
CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.o: __cmrc_sd_res/lib.cpp
CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.o: CMakeFiles/sd_res.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.o -MF CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.o.d -o CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.o -c /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/__cmrc_sd_res/lib.cpp

CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/__cmrc_sd_res/lib.cpp > CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.i

CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/__cmrc_sd_res/lib.cpp -o CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.s

CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.o: CMakeFiles/sd_res.dir/flags.make
CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.o: __cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp
CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.o: CMakeFiles/sd_res.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.o -MF CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.o.d -o CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.o -c /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp

CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp > CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.i

CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp -o CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.s

# Object files for target sd_res
sd_res_OBJECTS = \
"CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.o" \
"CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.o"

# External object files for target sd_res
sd_res_EXTERNAL_OBJECTS =

libsd_res.a: CMakeFiles/sd_res.dir/__cmrc_sd_res/lib.cpp.o
libsd_res.a: CMakeFiles/sd_res.dir/__cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp.o
libsd_res.a: CMakeFiles/sd_res.dir/build.make
libsd_res.a: CMakeFiles/sd_res.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libsd_res.a"
	$(CMAKE_COMMAND) -P CMakeFiles/sd_res.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sd_res.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sd_res.dir/build: libsd_res.a
.PHONY : CMakeFiles/sd_res.dir/build

CMakeFiles/sd_res.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sd_res.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sd_res.dir/clean

CMakeFiles/sd_res.dir/depend: __cmrc_sd_res/intermediate/fonts/Chalkduster.ttf.cpp
CMakeFiles/sd_res.dir/depend: __cmrc_sd_res/lib.cpp
	cd /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build /Users/pawandeepsingh/Documents/Development/GUI_cpp/sd_cpp_ui/build/CMakeFiles/sd_res.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sd_res.dir/depend

