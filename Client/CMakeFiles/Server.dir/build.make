# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/yanivdan/Desktop/prog/Chat_App/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yanivdan/Desktop/prog/Chat_App/Client

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/src/client.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/client.cpp.o: src/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yanivdan/Desktop/prog/Chat_App/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server.dir/src/client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/src/client.cpp.o -c /home/yanivdan/Desktop/prog/Chat_App/Client/src/client.cpp

CMakeFiles/Server.dir/src/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/src/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yanivdan/Desktop/prog/Chat_App/Client/src/client.cpp > CMakeFiles/Server.dir/src/client.cpp.i

CMakeFiles/Server.dir/src/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/src/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yanivdan/Desktop/prog/Chat_App/Client/src/client.cpp -o CMakeFiles/Server.dir/src/client.cpp.s

CMakeFiles/Server.dir/src/client_test.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/client_test.cpp.o: src/client_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yanivdan/Desktop/prog/Chat_App/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Server.dir/src/client_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/src/client_test.cpp.o -c /home/yanivdan/Desktop/prog/Chat_App/Client/src/client_test.cpp

CMakeFiles/Server.dir/src/client_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/src/client_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yanivdan/Desktop/prog/Chat_App/Client/src/client_test.cpp > CMakeFiles/Server.dir/src/client_test.cpp.i

CMakeFiles/Server.dir/src/client_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/src/client_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yanivdan/Desktop/prog/Chat_App/Client/src/client_test.cpp -o CMakeFiles/Server.dir/src/client_test.cpp.s

CMakeFiles/Server.dir/src/main_cl.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/src/main_cl.cpp.o: src/main_cl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yanivdan/Desktop/prog/Chat_App/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Server.dir/src/main_cl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/src/main_cl.cpp.o -c /home/yanivdan/Desktop/prog/Chat_App/Client/src/main_cl.cpp

CMakeFiles/Server.dir/src/main_cl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/src/main_cl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yanivdan/Desktop/prog/Chat_App/Client/src/main_cl.cpp > CMakeFiles/Server.dir/src/main_cl.cpp.i

CMakeFiles/Server.dir/src/main_cl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/src/main_cl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yanivdan/Desktop/prog/Chat_App/Client/src/main_cl.cpp -o CMakeFiles/Server.dir/src/main_cl.cpp.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/src/client.cpp.o" \
"CMakeFiles/Server.dir/src/client_test.cpp.o" \
"CMakeFiles/Server.dir/src/main_cl.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/src/client.cpp.o
Server: CMakeFiles/Server.dir/src/client_test.cpp.o
Server: CMakeFiles/Server.dir/src/main_cl.cpp.o
Server: CMakeFiles/Server.dir/build.make
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yanivdan/Desktop/prog/Chat_App/Client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server

.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd /home/yanivdan/Desktop/prog/Chat_App/Client && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yanivdan/Desktop/prog/Chat_App/Client /home/yanivdan/Desktop/prog/Chat_App/Client /home/yanivdan/Desktop/prog/Chat_App/Client /home/yanivdan/Desktop/prog/Chat_App/Client /home/yanivdan/Desktop/prog/Chat_App/Client/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend

