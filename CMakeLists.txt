cmake_minimum_required(VERSION 3.10)
project(simple_pc_project
    VERSION 1.0
    DESCRIPTION "A simple project to demonstrate the producer-consumer pattern"
    LANGUAGES CXX)
add_executable(product_consumer main.cpp block_deque.cpp)
set_target_properties(product_consumer PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)