# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = /home/dj/uni/s3/ipk_assignments/blatt05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dj/uni/s3/ipk_assignments/blatt05/builds

# Include any dependencies generated for this target.
include CMakeFiles/readvetor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/readvetor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/readvetor.dir/flags.make

CMakeFiles/readvetor.dir/readvector.cc.o: CMakeFiles/readvetor.dir/flags.make
CMakeFiles/readvetor.dir/readvector.cc.o: ../readvector.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dj/uni/s3/ipk_assignments/blatt05/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/readvetor.dir/readvector.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/readvetor.dir/readvector.cc.o -c /home/dj/uni/s3/ipk_assignments/blatt05/readvector.cc

CMakeFiles/readvetor.dir/readvector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/readvetor.dir/readvector.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dj/uni/s3/ipk_assignments/blatt05/readvector.cc > CMakeFiles/readvetor.dir/readvector.cc.i

CMakeFiles/readvetor.dir/readvector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/readvetor.dir/readvector.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dj/uni/s3/ipk_assignments/blatt05/readvector.cc -o CMakeFiles/readvetor.dir/readvector.cc.s

CMakeFiles/readvetor.dir/io.cc.o: CMakeFiles/readvetor.dir/flags.make
CMakeFiles/readvetor.dir/io.cc.o: ../io.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dj/uni/s3/ipk_assignments/blatt05/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/readvetor.dir/io.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/readvetor.dir/io.cc.o -c /home/dj/uni/s3/ipk_assignments/blatt05/io.cc

CMakeFiles/readvetor.dir/io.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/readvetor.dir/io.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dj/uni/s3/ipk_assignments/blatt05/io.cc > CMakeFiles/readvetor.dir/io.cc.i

CMakeFiles/readvetor.dir/io.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/readvetor.dir/io.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dj/uni/s3/ipk_assignments/blatt05/io.cc -o CMakeFiles/readvetor.dir/io.cc.s

# Object files for target readvetor
readvetor_OBJECTS = \
"CMakeFiles/readvetor.dir/readvector.cc.o" \
"CMakeFiles/readvetor.dir/io.cc.o"

# External object files for target readvetor
readvetor_EXTERNAL_OBJECTS =

readvetor: CMakeFiles/readvetor.dir/readvector.cc.o
readvetor: CMakeFiles/readvetor.dir/io.cc.o
readvetor: CMakeFiles/readvetor.dir/build.make
readvetor: CMakeFiles/readvetor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dj/uni/s3/ipk_assignments/blatt05/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable readvetor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/readvetor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/readvetor.dir/build: readvetor

.PHONY : CMakeFiles/readvetor.dir/build

CMakeFiles/readvetor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/readvetor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/readvetor.dir/clean

CMakeFiles/readvetor.dir/depend:
	cd /home/dj/uni/s3/ipk_assignments/blatt05/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dj/uni/s3/ipk_assignments/blatt05 /home/dj/uni/s3/ipk_assignments/blatt05 /home/dj/uni/s3/ipk_assignments/blatt05/builds /home/dj/uni/s3/ipk_assignments/blatt05/builds /home/dj/uni/s3/ipk_assignments/blatt05/builds/CMakeFiles/readvetor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/readvetor.dir/depend

