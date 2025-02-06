cmake_minimum_required(VERSION 3.31)

project(CppGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
    SDL
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        release-3.2.2
)

FetchContent_MakeAvailable(SDL)

add_subdirectory(libs)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} SDL3-static Game)
