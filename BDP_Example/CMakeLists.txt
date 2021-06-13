cmake_minimum_required(VERSION 3.9)

set(BDP_EX_SOURCES
    src/BDP_Example.cpp
)
add_executable(BDPExample
    ${BDP_EX_SOURCES}
)