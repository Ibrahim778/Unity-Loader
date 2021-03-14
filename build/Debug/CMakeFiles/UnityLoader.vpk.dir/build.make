# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ibrahim/GitRepos/Unity-Loader

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ibrahim/GitRepos/Unity-Loader/build/Debug

# Utility rule file for UnityLoader.vpk.

# Include the progress variables for this target.
include CMakeFiles/UnityLoader.vpk.dir/progress.make

CMakeFiles/UnityLoader.vpk: UnityLoader.vpk.out
	/usr/bin/cmake -E copy /home/ibrahim/GitRepos/Unity-Loader/build/Debug/UnityLoader.vpk.out UnityLoader.vpk

UnityLoader.vpk.out: UnityLoader.vpk_param.sfo
UnityLoader.vpk.out: UnityLoader.self
UnityLoader.vpk.out: ../../sce_sys
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ibrahim/GitRepos/Unity-Loader/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building vpk UnityLoader.vpk"
	/usr/local/vitasdk/bin/vita-pack-vpk -a /home/ibrahim/GitRepos/Unity-Loader/sce_sys=sce_sys -s /home/ibrahim/GitRepos/Unity-Loader/build/Debug/UnityLoader.vpk_param.sfo -b /home/ibrahim/GitRepos/Unity-Loader/build/Debug/UnityLoader.self /home/ibrahim/GitRepos/Unity-Loader/build/Debug/UnityLoader.vpk.out

UnityLoader.vpk_param.sfo: UnityLoader.self
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ibrahim/GitRepos/Unity-Loader/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating param.sfo for UnityLoader.vpk"
	/usr/local/vitasdk/bin/vita-mksfoex -s APP_VER=01.10 -s TITLE_ID=UNITYLOAD Unity\ Loader /home/ibrahim/GitRepos/Unity-Loader/build/Debug/UnityLoader.vpk_param.sfo

UnityLoader.vpk: CMakeFiles/UnityLoader.vpk
UnityLoader.vpk: UnityLoader.vpk.out
UnityLoader.vpk: UnityLoader.vpk_param.sfo
UnityLoader.vpk: CMakeFiles/UnityLoader.vpk.dir/build.make

.PHONY : UnityLoader.vpk

# Rule to build all files generated by this target.
CMakeFiles/UnityLoader.vpk.dir/build: UnityLoader.vpk

.PHONY : CMakeFiles/UnityLoader.vpk.dir/build

CMakeFiles/UnityLoader.vpk.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UnityLoader.vpk.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UnityLoader.vpk.dir/clean

CMakeFiles/UnityLoader.vpk.dir/depend:
	cd /home/ibrahim/GitRepos/Unity-Loader/build/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ibrahim/GitRepos/Unity-Loader /home/ibrahim/GitRepos/Unity-Loader /home/ibrahim/GitRepos/Unity-Loader/build/Debug /home/ibrahim/GitRepos/Unity-Loader/build/Debug /home/ibrahim/GitRepos/Unity-Loader/build/Debug/CMakeFiles/UnityLoader.vpk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UnityLoader.vpk.dir/depend

