project(Game)

set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/Game/Game.h)
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/Game.cpp)

add_library(Game STATIC ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)


target_link_libraries(${PROJECT_NAME} SDL3-static)
