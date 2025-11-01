cmake_minimum_required(VERSION 4.0)
project(Assignment3-QuickSelect)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GoogleTest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
#Test sweeps
add_executable(random_tests
        Randomised/randomMain.cpp
        Randomised/random_QuickSelect.cpp
)

add_executable(det_tests
        Deterministic/detMain.cpp
        Deterministic/Determinitstic.cpp
)

# Link GoogleTest and pthread
target_link_libraries(random_tests ${GTEST_LIBRARIES} pthread)
target_link_libraries(det_tests ${GTEST_LIBRARIES} pthread)


# Enable testing
enable_testing()
add_test(NAME Det COMMAND det_tests)
add_test(NAME Rand COMMAND random_tests)