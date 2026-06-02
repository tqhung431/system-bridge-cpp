include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/v1.14.x.zip
)

# Forcing GTest to use shared runtime matching MSVC defaults
# To ensure consistent runtime linkage for googldtest under Visual Studio/MSVC
set(gtest_force_shared_crt ON CACHE BOOL ""  FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(SystemBridgeTests test_handle.cpp)
target_link_libraries(SystemBridgeTests PRIVATE SystemBridgeCore gtest_main)

include(GoogleTest)
gtest_discover_tests(SystemBridgeTests)