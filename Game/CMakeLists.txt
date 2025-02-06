project(Game)

set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/Game/Game.h)
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/Game.cpp)

add_library(Game STATIC ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Game
    ${CMAKE_CURRENT_SOURCE_DIR}/src)
