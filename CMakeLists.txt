cmake_minimum_required(VERSION 3.25)

project(verilator_inout_issue)
find_package(verilator)

include_directories(include)

add_executable(test
    main.cpp
    tests/bidir.cpp
)

verilate(test SOURCES rtl/bidir.sv TRACE)
