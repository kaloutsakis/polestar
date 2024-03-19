cmake_minimum_required(VERSION 3.28.0)

project(PLAYGROUND VERSION 0.1.0)

# homebrew include and lib directories
link_directories("/opt/homebrew/lib")
include_directories("/opt/homebrew/include")

# Project base include directories
include_directories(src)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(src/sdk)
add_subdirectory(src/client)
add_subdirectory(src/server)
add_subdirectory(src/uv)