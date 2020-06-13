cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

set(dir "${CMAKE_CURRENT_SOURCE_DIR}/RELEASE")


set(CMAKE_BUILD_DIRECTORY ${dir})

include_directories(lib)
add_executable(bdv_server server.c erproc.c)	
