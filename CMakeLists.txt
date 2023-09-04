cmake_minimum_required(VERSION 3.0.0)
project(designpatern VERSION 0.1.0)

include_directories(include  include/Behavioral include/Creational include/Structural include/Algorithm)
file(GLOB SOURCES "main.cpp" "src/*.cpp" "src/Behavioral/*.cpp" "src/Creational/*.cpp" "src/Structural/*.cpp" "src/Algorithm/*.cpp" "src/Algorithm/Stack.cpp")
add_executable(designpatern ${SOURCES})
target_link_libraries(designpatern pthread)

