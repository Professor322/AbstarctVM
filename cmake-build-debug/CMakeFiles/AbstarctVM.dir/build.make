# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/professor/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/professor/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/professor/SchoolProjects/AbstarctVM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/professor/SchoolProjects/AbstarctVM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AbstarctVM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AbstarctVM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AbstarctVM.dir/flags.make

CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.o: CMakeFiles/AbstarctVM.dir/flags.make
CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.o: ../src/IOperand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/professor/SchoolProjects/AbstarctVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.o -c /home/professor/SchoolProjects/AbstarctVM/src/IOperand.cpp

CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/professor/SchoolProjects/AbstarctVM/src/IOperand.cpp > CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.i

CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/professor/SchoolProjects/AbstarctVM/src/IOperand.cpp -o CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.s

CMakeFiles/AbstarctVM.dir/src/main.cpp.o: CMakeFiles/AbstarctVM.dir/flags.make
CMakeFiles/AbstarctVM.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/professor/SchoolProjects/AbstarctVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AbstarctVM.dir/src/main.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstarctVM.dir/src/main.cpp.o -c /home/professor/SchoolProjects/AbstarctVM/src/main.cpp

CMakeFiles/AbstarctVM.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstarctVM.dir/src/main.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/professor/SchoolProjects/AbstarctVM/src/main.cpp > CMakeFiles/AbstarctVM.dir/src/main.cpp.i

CMakeFiles/AbstarctVM.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstarctVM.dir/src/main.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/professor/SchoolProjects/AbstarctVM/src/main.cpp -o CMakeFiles/AbstarctVM.dir/src/main.cpp.s

CMakeFiles/AbstarctVM.dir/src/Utils.cpp.o: CMakeFiles/AbstarctVM.dir/flags.make
CMakeFiles/AbstarctVM.dir/src/Utils.cpp.o: ../src/Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/professor/SchoolProjects/AbstarctVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AbstarctVM.dir/src/Utils.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstarctVM.dir/src/Utils.cpp.o -c /home/professor/SchoolProjects/AbstarctVM/src/Utils.cpp

CMakeFiles/AbstarctVM.dir/src/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstarctVM.dir/src/Utils.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/professor/SchoolProjects/AbstarctVM/src/Utils.cpp > CMakeFiles/AbstarctVM.dir/src/Utils.cpp.i

CMakeFiles/AbstarctVM.dir/src/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstarctVM.dir/src/Utils.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/professor/SchoolProjects/AbstarctVM/src/Utils.cpp -o CMakeFiles/AbstarctVM.dir/src/Utils.cpp.s

CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.o: CMakeFiles/AbstarctVM.dir/flags.make
CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.o: ../src/OperandDerived.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/professor/SchoolProjects/AbstarctVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.o -c /home/professor/SchoolProjects/AbstarctVM/src/OperandDerived.cpp

CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/professor/SchoolProjects/AbstarctVM/src/OperandDerived.cpp > CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.i

CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/professor/SchoolProjects/AbstarctVM/src/OperandDerived.cpp -o CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.s

CMakeFiles/AbstarctVM.dir/src/Stack.cpp.o: CMakeFiles/AbstarctVM.dir/flags.make
CMakeFiles/AbstarctVM.dir/src/Stack.cpp.o: ../src/Stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/professor/SchoolProjects/AbstarctVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AbstarctVM.dir/src/Stack.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstarctVM.dir/src/Stack.cpp.o -c /home/professor/SchoolProjects/AbstarctVM/src/Stack.cpp

CMakeFiles/AbstarctVM.dir/src/Stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstarctVM.dir/src/Stack.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/professor/SchoolProjects/AbstarctVM/src/Stack.cpp > CMakeFiles/AbstarctVM.dir/src/Stack.cpp.i

CMakeFiles/AbstarctVM.dir/src/Stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstarctVM.dir/src/Stack.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/professor/SchoolProjects/AbstarctVM/src/Stack.cpp -o CMakeFiles/AbstarctVM.dir/src/Stack.cpp.s

CMakeFiles/AbstarctVM.dir/src/Engine.cpp.o: CMakeFiles/AbstarctVM.dir/flags.make
CMakeFiles/AbstarctVM.dir/src/Engine.cpp.o: ../src/Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/professor/SchoolProjects/AbstarctVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AbstarctVM.dir/src/Engine.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstarctVM.dir/src/Engine.cpp.o -c /home/professor/SchoolProjects/AbstarctVM/src/Engine.cpp

CMakeFiles/AbstarctVM.dir/src/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstarctVM.dir/src/Engine.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/professor/SchoolProjects/AbstarctVM/src/Engine.cpp > CMakeFiles/AbstarctVM.dir/src/Engine.cpp.i

CMakeFiles/AbstarctVM.dir/src/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstarctVM.dir/src/Engine.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/professor/SchoolProjects/AbstarctVM/src/Engine.cpp -o CMakeFiles/AbstarctVM.dir/src/Engine.cpp.s

CMakeFiles/AbstarctVM.dir/src/Token.cpp.o: CMakeFiles/AbstarctVM.dir/flags.make
CMakeFiles/AbstarctVM.dir/src/Token.cpp.o: ../src/Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/professor/SchoolProjects/AbstarctVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/AbstarctVM.dir/src/Token.cpp.o"
	/usr/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AbstarctVM.dir/src/Token.cpp.o -c /home/professor/SchoolProjects/AbstarctVM/src/Token.cpp

CMakeFiles/AbstarctVM.dir/src/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AbstarctVM.dir/src/Token.cpp.i"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/professor/SchoolProjects/AbstarctVM/src/Token.cpp > CMakeFiles/AbstarctVM.dir/src/Token.cpp.i

CMakeFiles/AbstarctVM.dir/src/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AbstarctVM.dir/src/Token.cpp.s"
	/usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/professor/SchoolProjects/AbstarctVM/src/Token.cpp -o CMakeFiles/AbstarctVM.dir/src/Token.cpp.s

# Object files for target AbstarctVM
AbstarctVM_OBJECTS = \
"CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.o" \
"CMakeFiles/AbstarctVM.dir/src/main.cpp.o" \
"CMakeFiles/AbstarctVM.dir/src/Utils.cpp.o" \
"CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.o" \
"CMakeFiles/AbstarctVM.dir/src/Stack.cpp.o" \
"CMakeFiles/AbstarctVM.dir/src/Engine.cpp.o" \
"CMakeFiles/AbstarctVM.dir/src/Token.cpp.o"

# External object files for target AbstarctVM
AbstarctVM_EXTERNAL_OBJECTS =

AbstarctVM: CMakeFiles/AbstarctVM.dir/src/IOperand.cpp.o
AbstarctVM: CMakeFiles/AbstarctVM.dir/src/main.cpp.o
AbstarctVM: CMakeFiles/AbstarctVM.dir/src/Utils.cpp.o
AbstarctVM: CMakeFiles/AbstarctVM.dir/src/OperandDerived.cpp.o
AbstarctVM: CMakeFiles/AbstarctVM.dir/src/Stack.cpp.o
AbstarctVM: CMakeFiles/AbstarctVM.dir/src/Engine.cpp.o
AbstarctVM: CMakeFiles/AbstarctVM.dir/src/Token.cpp.o
AbstarctVM: CMakeFiles/AbstarctVM.dir/build.make
AbstarctVM: CMakeFiles/AbstarctVM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/professor/SchoolProjects/AbstarctVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable AbstarctVM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AbstarctVM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AbstarctVM.dir/build: AbstarctVM

.PHONY : CMakeFiles/AbstarctVM.dir/build

CMakeFiles/AbstarctVM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AbstarctVM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AbstarctVM.dir/clean

CMakeFiles/AbstarctVM.dir/depend:
	cd /home/professor/SchoolProjects/AbstarctVM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/professor/SchoolProjects/AbstarctVM /home/professor/SchoolProjects/AbstarctVM /home/professor/SchoolProjects/AbstarctVM/cmake-build-debug /home/professor/SchoolProjects/AbstarctVM/cmake-build-debug /home/professor/SchoolProjects/AbstarctVM/cmake-build-debug/CMakeFiles/AbstarctVM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AbstarctVM.dir/depend

