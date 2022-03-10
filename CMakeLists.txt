project(Camshake)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic --std=c++17")

include_directories(external)

set(SRC_FILES main.cpp
  Camera.cpp
  external/Animation.cpp
  external/AnimatedSprite.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


link_libraries(sfml-graphics sfml-window sfml-system)

add_executable(camshake ${SRC_FILES})

add_custom_command(TARGET camshake POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/assets/"
      $<TARGET_FILE_DIR:camshake>)
