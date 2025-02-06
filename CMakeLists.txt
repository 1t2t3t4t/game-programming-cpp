cmake_minimum_required(VERSION 3.15)

project(CppGame)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
    SDL
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        release-2.30.11
)

FetchContent_MakeAvailable(SDL)

add_subdirectory(Game)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} SDL2 Game)
