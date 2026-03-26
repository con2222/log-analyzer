cmake_minimum_required(VERSION 4.2.3 FATAL_ERROR)

project(log-analyzer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)

add_executable(log-analyzer src/main.cpp src/LogParser.cpp)

target_include_directories(log-analyzer PRIVATE src/)

find_package(Threads REQUIRED)
target_link_libraries(log-analyzer PRIVATE Threads::Threads)

if (NOT MSVC)
    target_compile_options(log-analyzer PRIVATE -Wall -Wextra -Werror)
endif()
