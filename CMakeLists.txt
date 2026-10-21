
cmake_minimum_required(VERSION 3.20)
project(VendingMachine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source code for the vending machine
add_executable(VendingMachine
    src/main.cpp
    src/Product.cpp
    src/VendingMachine.cpp
    src/State.cpp
)

# Enable unit testing
include(CTest)

if(BUILD_TESTING)
    # Download GoogleTest automatically
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Create the test executable
    add_executable(VendingMachineTests
        tests/VendingMachineTests.cpp
        src/Product.cpp
        src/VendingMachine.cpp
        src/State.cpp
    )

    target_include_directories(VendingMachineTests PRIVATE src)

    target_link_libraries(VendingMachineTests
        PRIVATE GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(VendingMachineTests)
endif()
