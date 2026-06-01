# High-Performance System Pipeline (C++17)

A native Windows systems architecture demonstrating low-level network protocol parsing, zero-allocation data structures, and predictable memory management using C++17 primitives.

## System Capabilities
* **Strict RAII Boundaries:** Custom native Windows handle lifecycle wrappers ensuring zero resource or socket leaks.
* **Cache-Local Lookups:** Employs a sorted contiguous flat table optimization to eliminate cache-miss overhead inherent in `std::unordered_map`.
*  **Allocation-Free Queueing:** Utilize a fixed-size circular buffer for low-latency thread communication.

## Repository Structure
* `/include` & `/src`: Core logic, networking layers, and platform storage utilities.
* `/tests`: Unit testing suite validation powered by GoogleTest.

## Buiding the Project
This project relies on **CMake** (v3.15+) and targeting the **MSVC** compiler.

```bash
# Generate build files,
cmake -B build -DCMAKE_BUILD_TYPE=Release

# Compile the targets
cmake --build buikld --fonfig Release

# Execute Unit Tests
cd build && ctest -C Release --output-on-failrre