# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /AquaticSimulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /AquaticSimulation/build

# Include any dependencies generated for this target.
include CMakeFiles/AquaticSimulation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AquaticSimulation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AquaticSimulation.dir/flags.make

CMakeFiles/AquaticSimulation.dir/src/main.cpp.o: CMakeFiles/AquaticSimulation.dir/flags.make
CMakeFiles/AquaticSimulation.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/AquaticSimulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AquaticSimulation.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AquaticSimulation.dir/src/main.cpp.o -c /AquaticSimulation/src/main.cpp

CMakeFiles/AquaticSimulation.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AquaticSimulation.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /AquaticSimulation/src/main.cpp > CMakeFiles/AquaticSimulation.dir/src/main.cpp.i

CMakeFiles/AquaticSimulation.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AquaticSimulation.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /AquaticSimulation/src/main.cpp -o CMakeFiles/AquaticSimulation.dir/src/main.cpp.s

CMakeFiles/AquaticSimulation.dir/src/Point.cpp.o: CMakeFiles/AquaticSimulation.dir/flags.make
CMakeFiles/AquaticSimulation.dir/src/Point.cpp.o: ../src/Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/AquaticSimulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AquaticSimulation.dir/src/Point.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AquaticSimulation.dir/src/Point.cpp.o -c /AquaticSimulation/src/Point.cpp

CMakeFiles/AquaticSimulation.dir/src/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AquaticSimulation.dir/src/Point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /AquaticSimulation/src/Point.cpp > CMakeFiles/AquaticSimulation.dir/src/Point.cpp.i

CMakeFiles/AquaticSimulation.dir/src/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AquaticSimulation.dir/src/Point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /AquaticSimulation/src/Point.cpp -o CMakeFiles/AquaticSimulation.dir/src/Point.cpp.s

CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.o: CMakeFiles/AquaticSimulation.dir/flags.make
CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.o: ../src/AquaticAnimal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/AquaticSimulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.o -c /AquaticSimulation/src/AquaticAnimal.cpp

CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /AquaticSimulation/src/AquaticAnimal.cpp > CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.i

CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /AquaticSimulation/src/AquaticAnimal.cpp -o CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.s

CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.o: CMakeFiles/AquaticSimulation.dir/flags.make
CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.o: ../src/AquaticEnvironment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/AquaticSimulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.o -c /AquaticSimulation/src/AquaticEnvironment.cpp

CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /AquaticSimulation/src/AquaticEnvironment.cpp > CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.i

CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /AquaticSimulation/src/AquaticEnvironment.cpp -o CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.s

CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.o: CMakeFiles/AquaticSimulation.dir/flags.make
CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.o: ../src/GeneticAlgorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/AquaticSimulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.o -c /AquaticSimulation/src/GeneticAlgorithm.cpp

CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /AquaticSimulation/src/GeneticAlgorithm.cpp > CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.i

CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /AquaticSimulation/src/GeneticAlgorithm.cpp -o CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.s

# Object files for target AquaticSimulation
AquaticSimulation_OBJECTS = \
"CMakeFiles/AquaticSimulation.dir/src/main.cpp.o" \
"CMakeFiles/AquaticSimulation.dir/src/Point.cpp.o" \
"CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.o" \
"CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.o" \
"CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.o"

# External object files for target AquaticSimulation
AquaticSimulation_EXTERNAL_OBJECTS =

AquaticSimulation: CMakeFiles/AquaticSimulation.dir/src/main.cpp.o
AquaticSimulation: CMakeFiles/AquaticSimulation.dir/src/Point.cpp.o
AquaticSimulation: CMakeFiles/AquaticSimulation.dir/src/AquaticAnimal.cpp.o
AquaticSimulation: CMakeFiles/AquaticSimulation.dir/src/AquaticEnvironment.cpp.o
AquaticSimulation: CMakeFiles/AquaticSimulation.dir/src/GeneticAlgorithm.cpp.o
AquaticSimulation: CMakeFiles/AquaticSimulation.dir/build.make
AquaticSimulation: CMakeFiles/AquaticSimulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/AquaticSimulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable AquaticSimulation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AquaticSimulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AquaticSimulation.dir/build: AquaticSimulation

.PHONY : CMakeFiles/AquaticSimulation.dir/build

CMakeFiles/AquaticSimulation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AquaticSimulation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AquaticSimulation.dir/clean

CMakeFiles/AquaticSimulation.dir/depend:
	cd /AquaticSimulation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /AquaticSimulation /AquaticSimulation /AquaticSimulation/build /AquaticSimulation/build /AquaticSimulation/build/CMakeFiles/AquaticSimulation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AquaticSimulation.dir/depend

