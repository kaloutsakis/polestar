cmake_minimum_required(VERSION 3.22.0)
project(UV VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(binuv)

target_include_directories(binuv
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(binuv
    PRIVATE main.c
    PRIVATE ILogManager.cpp
)

target_link_libraries(binuv
    PRIVATE uv
    PRIVATE fmt
)

target_compile_options(binuv
    PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
)