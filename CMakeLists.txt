cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(CppGameProgramming)

include(build/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(src)
file(GLOB SRC_FILES src/*.cpp)

add_executable(CppGameProgramming ${SRC_FILES})
target_link_libraries(CppGameProgramming ${CONAN_LIBS})