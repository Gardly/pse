cmake_minimum_required(VERSION 3.6)
project(pse)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror -O2")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

set(SOURCE_FILES main.cpp Airplane.cpp Airplane.h DesignByContract.cpp DesignByContract.h Runway.cpp Runway.h Airport.cpp Airport.h Gate.cpp Gate.h AirTrafficController.cpp AirTrafficController.h)
add_executable(pse ${SOURCE_FILES})