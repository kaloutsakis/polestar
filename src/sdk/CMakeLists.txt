cmake_minimum_required(VERSION 3.22.0)

project(SDK VERSION 0.1.0)

add_library(sdk SHARED)

target_include_directories(sdk
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(sdk
    PRIVATE LogManager.cpp
)

target_compile_options(sdk
    PRIVATE -std=c++14
)

target_link_libraries(sdk
    PRIVATE uv
    PRIVATE fmt
)