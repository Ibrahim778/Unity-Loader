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
CMAKE_SOURCE_DIR = /home/ibrahim/GitRepos/Unity-Loader/launchPlugin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ibrahim/GitRepos/Unity-Loader/launchPlugin

# Include any dependencies generated for this target.
include CMakeFiles/ds4vita.elf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ds4vita.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ds4vita.elf.dir/flags.make

CMakeFiles/ds4vita.elf.dir/main.c.obj: CMakeFiles/ds4vita.elf.dir/flags.make
CMakeFiles/ds4vita.elf.dir/main.c.obj: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ibrahim/GitRepos/Unity-Loader/launchPlugin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ds4vita.elf.dir/main.c.obj"
	/usr/local/vitasdk/bin/arm-vita-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ds4vita.elf.dir/main.c.obj   -c /home/ibrahim/GitRepos/Unity-Loader/launchPlugin/main.c

CMakeFiles/ds4vita.elf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ds4vita.elf.dir/main.c.i"
	/usr/local/vitasdk/bin/arm-vita-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ibrahim/GitRepos/Unity-Loader/launchPlugin/main.c > CMakeFiles/ds4vita.elf.dir/main.c.i

CMakeFiles/ds4vita.elf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ds4vita.elf.dir/main.c.s"
	/usr/local/vitasdk/bin/arm-vita-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ibrahim/GitRepos/Unity-Loader/launchPlugin/main.c -o CMakeFiles/ds4vita.elf.dir/main.c.s

CMakeFiles/ds4vita.elf.dir/main.c.obj.requires:

.PHONY : CMakeFiles/ds4vita.elf.dir/main.c.obj.requires

CMakeFiles/ds4vita.elf.dir/main.c.obj.provides: CMakeFiles/ds4vita.elf.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles/ds4vita.elf.dir/build.make CMakeFiles/ds4vita.elf.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/ds4vita.elf.dir/main.c.obj.provides

CMakeFiles/ds4vita.elf.dir/main.c.obj.provides.build: CMakeFiles/ds4vita.elf.dir/main.c.obj


# Object files for target ds4vita.elf
ds4vita_elf_OBJECTS = \
"CMakeFiles/ds4vita.elf.dir/main.c.obj"

# External object files for target ds4vita.elf
ds4vita_elf_EXTERNAL_OBJECTS =

ds4vita.elf: CMakeFiles/ds4vita.elf.dir/main.c.obj
ds4vita.elf: CMakeFiles/ds4vita.elf.dir/build.make
ds4vita.elf: CMakeFiles/ds4vita.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ibrahim/GitRepos/Unity-Loader/launchPlugin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ds4vita.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ds4vita.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ds4vita.elf.dir/build: ds4vita.elf

.PHONY : CMakeFiles/ds4vita.elf.dir/build

CMakeFiles/ds4vita.elf.dir/requires: CMakeFiles/ds4vita.elf.dir/main.c.obj.requires

.PHONY : CMakeFiles/ds4vita.elf.dir/requires

CMakeFiles/ds4vita.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ds4vita.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ds4vita.elf.dir/clean

CMakeFiles/ds4vita.elf.dir/depend:
	cd /home/ibrahim/GitRepos/Unity-Loader/launchPlugin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ibrahim/GitRepos/Unity-Loader/launchPlugin /home/ibrahim/GitRepos/Unity-Loader/launchPlugin /home/ibrahim/GitRepos/Unity-Loader/launchPlugin /home/ibrahim/GitRepos/Unity-Loader/launchPlugin /home/ibrahim/GitRepos/Unity-Loader/launchPlugin/CMakeFiles/ds4vita.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ds4vita.elf.dir/depend
