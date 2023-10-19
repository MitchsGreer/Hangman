# ==============================================================================
# CMake file for C implementation of Hangman.
# ==============================================================================
cmake_minimum_required(VERSION 3.22)

# ------------------------------------------------------------------------------
# Project we will be compiling.
# ------------------------------------------------------------------------------
project(Hangman LANGUAGES C VERSION 1.0)

# ------------------------------------------------------------------------------
# Compiler standareds to use.
# ------------------------------------------------------------------------------
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# ------------------------------------------------------------------------------
# Source files to add.
# ------------------------------------------------------------------------------
set(SOURCES "")
list(APPEND SOURCES src/guess.c)
list(APPEND SOURCES src/hang_time.c)
list(APPEND SOURCES src/input.c)
list(APPEND SOURCES src/main.c)
list(APPEND SOURCES src/menu.c)
list(APPEND SOURCES src/play.c)
list(APPEND SOURCES src/scoreboard.c)
list(APPEND SOURCES src/stats.c)

# ------------------------------------------------------------------------------
# Executable and files needed to make it.
# ------------------------------------------------------------------------------
add_executable(Hangman ${SOURCES})

# ------------------------------------------------------------------------------
# Add include directories.
# ------------------------------------------------------------------------------
target_include_directories(Hangman PUBLIC include)
