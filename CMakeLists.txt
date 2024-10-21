# Set the minimum required CMake version and project name
cmake_minimum_required(VERSION 3.10)
project(DataExtractor)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find and include OpenSSL package
find_package(OpenSSL REQUIRED)

# Add executable target (main.cpp)
add_executable(DataExtractor src/main.cpp)

# Link OpenSSL libraries to the executable
target_link_libraries(DataExtractor PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Include directories for OpenSSL (if needed)
target_include_directories(DataExtractor PRIVATE ${OPENSSL_INCLUDE_DIR})
