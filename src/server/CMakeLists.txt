cmake_minimum_required(VERSION 3.22.0)

project(SERVER VERSION 0.1.0)

add_executable(server)

target_include_directories(server
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(server
    PRIVATE main.cpp
)

target_compile_options(server
    PRIVATE -std=c++17
)

target_link_libraries(server
    PRIVATE uv
)