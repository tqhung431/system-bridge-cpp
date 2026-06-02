cmake_minimum_required(VERSION 3.15)
project(SystemBridgeCpp LANGUAGES CXX)

#Enforce C++17 standard strictly
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable deep compiler warnings - absoolutely must for professional repos
if(MSVC)
    add_compile_options(/W4 /WX /permissive-)
else()
    add_compile_options(-Wall -Wextra -Werror)
endif()

# Define our core systems library target
add_library(SystemBridgeCore
    src/core/ScopeHandle.cpp
)

# Target-based include directories (cleaner than global include_directories)
target_include_directories(SystemBridgeCore PUBLIC include)

# Include Unit Tests sub-directory
add_subdirectory(tests)