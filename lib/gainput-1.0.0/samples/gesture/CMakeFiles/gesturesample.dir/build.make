# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/pixar/Cellar/cmake/3.9.0/bin/cmake

# The command to remove a file.
RM = /usr/local/pixar/Cellar/cmake/3.9.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nwaters/code/go_stop/lib/gainput-1.0.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nwaters/code/go_stop/lib/gainput-1.0.0

# Include any dependencies generated for this target.
include samples/gesture/CMakeFiles/gesturesample.dir/depend.make

# Include the progress variables for this target.
include samples/gesture/CMakeFiles/gesturesample.dir/progress.make

# Include the compile flags for this target's objects.
include samples/gesture/CMakeFiles/gesturesample.dir/flags.make

samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o: samples/gesture/CMakeFiles/gesturesample.dir/flags.make
samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o: samples/gesture/gesturesample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nwaters/code/go_stop/lib/gainput-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gesturesample.dir/gesturesample.cpp.o -c /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture/gesturesample.cpp

samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gesturesample.dir/gesturesample.cpp.i"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture/gesturesample.cpp > CMakeFiles/gesturesample.dir/gesturesample.cpp.i

samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gesturesample.dir/gesturesample.cpp.s"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture/gesturesample.cpp -o CMakeFiles/gesturesample.dir/gesturesample.cpp.s

samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o.requires:

.PHONY : samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o.requires

samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o.provides: samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o.requires
	$(MAKE) -f samples/gesture/CMakeFiles/gesturesample.dir/build.make samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o.provides.build
.PHONY : samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o.provides

samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o.provides.build: samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o


samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o: samples/gesture/CMakeFiles/gesturesample.dir/flags.make
samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o: samples/samplefw/SampleFramework.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nwaters/code/go_stop/lib/gainput-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o -c /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/samplefw/SampleFramework.cpp

samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.i"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/samplefw/SampleFramework.cpp > CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.i

samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.s"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/samplefw/SampleFramework.cpp -o CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.s

samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o.requires:

.PHONY : samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o.requires

samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o.provides: samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o.requires
	$(MAKE) -f samples/gesture/CMakeFiles/gesturesample.dir/build.make samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o.provides.build
.PHONY : samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o.provides

samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o.provides.build: samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o


# Object files for target gesturesample
gesturesample_OBJECTS = \
"CMakeFiles/gesturesample.dir/gesturesample.cpp.o" \
"CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o"

# External object files for target gesturesample
gesturesample_EXTERNAL_OBJECTS =

samples/gesture/gesturesample: samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o
samples/gesture/gesturesample: samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o
samples/gesture/gesturesample: samples/gesture/CMakeFiles/gesturesample.dir/build.make
samples/gesture/gesturesample: lib/libgainputstatic.a
samples/gesture/gesturesample: samples/gesture/CMakeFiles/gesturesample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nwaters/code/go_stop/lib/gainput-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable gesturesample"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gesturesample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
samples/gesture/CMakeFiles/gesturesample.dir/build: samples/gesture/gesturesample

.PHONY : samples/gesture/CMakeFiles/gesturesample.dir/build

samples/gesture/CMakeFiles/gesturesample.dir/requires: samples/gesture/CMakeFiles/gesturesample.dir/gesturesample.cpp.o.requires
samples/gesture/CMakeFiles/gesturesample.dir/requires: samples/gesture/CMakeFiles/gesturesample.dir/__/samplefw/SampleFramework.cpp.o.requires

.PHONY : samples/gesture/CMakeFiles/gesturesample.dir/requires

samples/gesture/CMakeFiles/gesturesample.dir/clean:
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture && $(CMAKE_COMMAND) -P CMakeFiles/gesturesample.dir/cmake_clean.cmake
.PHONY : samples/gesture/CMakeFiles/gesturesample.dir/clean

samples/gesture/CMakeFiles/gesturesample.dir/depend:
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nwaters/code/go_stop/lib/gainput-1.0.0 /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture /Users/nwaters/code/go_stop/lib/gainput-1.0.0 /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture/CMakeFiles/gesturesample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : samples/gesture/CMakeFiles/gesturesample.dir/depend

