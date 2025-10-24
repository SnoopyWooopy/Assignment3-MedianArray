cmake_minimum_required(VERSION 4.0)
project(Assignment3-QuickSelect)

set(CMAKE_CXX_STANDARD 20)

# Determinisic solution execuatable
add_executable(Assignment3-QuickSelect main.cpp
        Deterministic/Determinitstic.cpp
        Deterministic/Determinitstic.h)

# Random solution executable
add_executable(Assignment3-QuickSelect
        Randomised/random_QuickSelect.cpp
        Randomised/random_QuickSelect.h)
