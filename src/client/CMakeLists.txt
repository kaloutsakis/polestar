cmake_minimum_required(VERSION 3.22.0)

project(CLIENT VERSION 0.1.0)

add_executable(client)

target_include_directories(client
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(client
    PRIVATE main.cpp
)

target_compile_options(client
    PRIVATE -std=c++14
)

target_link_libraries(client
    PRIVATE uv
    PRIVATE fmt
)