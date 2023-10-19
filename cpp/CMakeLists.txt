# ==============================================================================
# CMake file for C++ implementation of Hangman.
# ==============================================================================
cmake_minimum_required(VERSION 3.22)

# ------------------------------------------------------------------------------
# Project we will be compiling.
# ------------------------------------------------------------------------------
project(Hangman LANGUAGES CXX VERSION 1.0)

# ------------------------------------------------------------------------------
# Compiler standareds to use.
# ------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ------------------------------------------------------------------------------
# Add Libraries to Build
# ------------------------------------------------------------------------------
add_subdirectory(lib/cpp_lib/menu/ cpp_lib/menu/build)

# ------------------------------------------------------------------------------
# Source files to add.
# ------------------------------------------------------------------------------
set(SOURCES "")
list(APPEND SOURCES src/main.cpp)
list(APPEND SOURCES src/play_menu_item.cpp)
list(APPEND SOURCES src/stats_menu_item.cpp)
list(APPEND SOURCES src/rules_menu_item.cpp)
list(APPEND SOURCES src/score_board_menu_item.cpp)

# ------------------------------------------------------------------------------
# Executable and files needed to make it.
# ------------------------------------------------------------------------------
add_executable(Hangman ${SOURCES})

# ------------------------------------------------------------------------------
# Add include directories.
# ------------------------------------------------------------------------------
target_include_directories(Hangman PUBLIC include)
target_include_directories(Hangman PUBLIC lib/cpp_lib/menu/include)

# ------------------------------------------------------------------------------
# Link in Libraries
# ------------------------------------------------------------------------------
target_link_libraries(Hangman libmenu)