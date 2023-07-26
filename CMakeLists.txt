cmake_minimum_required(VERSION 3.22.0)

project(PLAYGROUND VERSION 0.1.0)

# homebrew include and lib directories
link_directories("/opt/homebrew/lib")
include_directories("/opt/homebrew/include")

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(src/client)
add_subdirectory(src/server)
add_subdirectory(src/uv)