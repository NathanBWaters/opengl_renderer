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
include samples/basic/CMakeFiles/basicsample.dir/depend.make

# Include the progress variables for this target.
include samples/basic/CMakeFiles/basicsample.dir/progress.make

# Include the compile flags for this target's objects.
include samples/basic/CMakeFiles/basicsample.dir/flags.make

samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o: samples/basic/CMakeFiles/basicsample.dir/flags.make
samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o: samples/basic/basicsample_android.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nwaters/code/go_stop/lib/gainput-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicsample.dir/basicsample_android.cpp.o -c /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_android.cpp

samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicsample.dir/basicsample_android.cpp.i"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_android.cpp > CMakeFiles/basicsample.dir/basicsample_android.cpp.i

samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicsample.dir/basicsample_android.cpp.s"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_android.cpp -o CMakeFiles/basicsample.dir/basicsample_android.cpp.s

samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o.requires:

.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o.requires

samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o.provides: samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o.requires
	$(MAKE) -f samples/basic/CMakeFiles/basicsample.dir/build.make samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o.provides.build
.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o.provides

samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o.provides.build: samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o


samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o: samples/basic/CMakeFiles/basicsample.dir/flags.make
samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o: samples/basic/basicsample_android_generic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nwaters/code/go_stop/lib/gainput-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o -c /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_android_generic.cpp

samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.i"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_android_generic.cpp > CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.i

samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.s"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_android_generic.cpp -o CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.s

samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o.requires:

.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o.requires

samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o.provides: samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o.requires
	$(MAKE) -f samples/basic/CMakeFiles/basicsample.dir/build.make samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o.provides.build
.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o.provides

samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o.provides.build: samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o


samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o: samples/basic/CMakeFiles/basicsample.dir/flags.make
samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o: samples/basic/basicsample_linux.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nwaters/code/go_stop/lib/gainput-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicsample.dir/basicsample_linux.cpp.o -c /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_linux.cpp

samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicsample.dir/basicsample_linux.cpp.i"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_linux.cpp > CMakeFiles/basicsample.dir/basicsample_linux.cpp.i

samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicsample.dir/basicsample_linux.cpp.s"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_linux.cpp -o CMakeFiles/basicsample.dir/basicsample_linux.cpp.s

samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o.requires:

.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o.requires

samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o.provides: samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o.requires
	$(MAKE) -f samples/basic/CMakeFiles/basicsample.dir/build.make samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o.provides.build
.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o.provides

samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o.provides.build: samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o


samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o: samples/basic/CMakeFiles/basicsample.dir/flags.make
samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o: samples/basic/basicsample_win.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nwaters/code/go_stop/lib/gainput-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicsample.dir/basicsample_win.cpp.o -c /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_win.cpp

samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicsample.dir/basicsample_win.cpp.i"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_win.cpp > CMakeFiles/basicsample.dir/basicsample_win.cpp.i

samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicsample.dir/basicsample_win.cpp.s"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_win.cpp -o CMakeFiles/basicsample.dir/basicsample_win.cpp.s

samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o.requires:

.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o.requires

samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o.provides: samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o.requires
	$(MAKE) -f samples/basic/CMakeFiles/basicsample.dir/build.make samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o.provides.build
.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o.provides

samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o.provides.build: samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o


samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o: samples/basic/CMakeFiles/basicsample.dir/flags.make
samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o: samples/basic/basicsample_ios.mm
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nwaters/code/go_stop/lib/gainput-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicsample.dir/basicsample_ios.mm.o -c /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_ios.mm

samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicsample.dir/basicsample_ios.mm.i"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_ios.mm > CMakeFiles/basicsample.dir/basicsample_ios.mm.i

samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicsample.dir/basicsample_ios.mm.s"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_ios.mm -o CMakeFiles/basicsample.dir/basicsample_ios.mm.s

samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o.requires:

.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o.requires

samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o.provides: samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o.requires
	$(MAKE) -f samples/basic/CMakeFiles/basicsample.dir/build.make samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o.provides.build
.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o.provides

samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o.provides.build: samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o


samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o: samples/basic/CMakeFiles/basicsample.dir/flags.make
samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o: samples/basic/basicsample_mac.mm
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nwaters/code/go_stop/lib/gainput-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicsample.dir/basicsample_mac.mm.o -c /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_mac.mm

samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicsample.dir/basicsample_mac.mm.i"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_mac.mm > CMakeFiles/basicsample.dir/basicsample_mac.mm.i

samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicsample.dir/basicsample_mac.mm.s"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/basicsample_mac.mm -o CMakeFiles/basicsample.dir/basicsample_mac.mm.s

samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o.requires:

.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o.requires

samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o.provides: samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o.requires
	$(MAKE) -f samples/basic/CMakeFiles/basicsample.dir/build.make samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o.provides.build
.PHONY : samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o.provides

samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o.provides.build: samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o


# Object files for target basicsample
basicsample_OBJECTS = \
"CMakeFiles/basicsample.dir/basicsample_android.cpp.o" \
"CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o" \
"CMakeFiles/basicsample.dir/basicsample_linux.cpp.o" \
"CMakeFiles/basicsample.dir/basicsample_win.cpp.o" \
"CMakeFiles/basicsample.dir/basicsample_ios.mm.o" \
"CMakeFiles/basicsample.dir/basicsample_mac.mm.o"

# External object files for target basicsample
basicsample_EXTERNAL_OBJECTS =

samples/basic/basicsample: samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o
samples/basic/basicsample: samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o
samples/basic/basicsample: samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o
samples/basic/basicsample: samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o
samples/basic/basicsample: samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o
samples/basic/basicsample: samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o
samples/basic/basicsample: samples/basic/CMakeFiles/basicsample.dir/build.make
samples/basic/basicsample: lib/libgainputstatic.a
samples/basic/basicsample: samples/basic/CMakeFiles/basicsample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nwaters/code/go_stop/lib/gainput-1.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable basicsample"
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/basicsample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
samples/basic/CMakeFiles/basicsample.dir/build: samples/basic/basicsample

.PHONY : samples/basic/CMakeFiles/basicsample.dir/build

samples/basic/CMakeFiles/basicsample.dir/requires: samples/basic/CMakeFiles/basicsample.dir/basicsample_android.cpp.o.requires
samples/basic/CMakeFiles/basicsample.dir/requires: samples/basic/CMakeFiles/basicsample.dir/basicsample_android_generic.cpp.o.requires
samples/basic/CMakeFiles/basicsample.dir/requires: samples/basic/CMakeFiles/basicsample.dir/basicsample_linux.cpp.o.requires
samples/basic/CMakeFiles/basicsample.dir/requires: samples/basic/CMakeFiles/basicsample.dir/basicsample_win.cpp.o.requires
samples/basic/CMakeFiles/basicsample.dir/requires: samples/basic/CMakeFiles/basicsample.dir/basicsample_ios.mm.o.requires
samples/basic/CMakeFiles/basicsample.dir/requires: samples/basic/CMakeFiles/basicsample.dir/basicsample_mac.mm.o.requires

.PHONY : samples/basic/CMakeFiles/basicsample.dir/requires

samples/basic/CMakeFiles/basicsample.dir/clean:
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic && $(CMAKE_COMMAND) -P CMakeFiles/basicsample.dir/cmake_clean.cmake
.PHONY : samples/basic/CMakeFiles/basicsample.dir/clean

samples/basic/CMakeFiles/basicsample.dir/depend:
	cd /Users/nwaters/code/go_stop/lib/gainput-1.0.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nwaters/code/go_stop/lib/gainput-1.0.0 /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic /Users/nwaters/code/go_stop/lib/gainput-1.0.0 /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/CMakeFiles/basicsample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : samples/basic/CMakeFiles/basicsample.dir/depend
