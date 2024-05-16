cmake_minimum_required(VERSION 3.10)
project(AquaticSimulation)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SDL2 package
find_package(SDL2 REQUIRED)

# Include the SDL2 directory
include_directories(${SDL2_INCLUDE_DIRS} include)

# Add the executable
add_executable(AquaticSimulation
    src/main.cpp
    src/Point.cpp
    src/AquaticAnimal.cpp
    src/AquaticEnvironment.cpp
    src/GeneticAlgorithm.cpp
)

# Link the SDL2 library
target_link_libraries(AquaticSimulation ${SDL2_LIBRARIES})
