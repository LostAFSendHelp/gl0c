cmake_minimum_required(VERSION 3.10)

project(gl0c)

file(GLOB SOURCES "src/gl0c.cpp" "src/**/*.cpp")

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(gl0c ${SOURCES})
target_link_libraries(gl0c PRIVATE GLEW::GLEW glfw glm)