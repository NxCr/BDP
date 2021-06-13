cmake_minimum_required(VERSION 3.9)

set(BDP_SOURCES
    "src/udp_socket.c"
)
set(BDP_INCLUDE_DIRS_PR
    "include"
)
add_library(BDP STATIC
${BDP_SOURCES}
)
target_include_directories(BDP 
    PRIVATE ${BDP_INCLUDE_DIRS_PR})