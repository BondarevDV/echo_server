cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

project(client_tcp)

set(CMAKE_BUILD_TYPE Release)

add_definitions(-Wall -o2)

include_directories(${PROJECT_SOURCE_DIR}/../include)

file( GLOB 
	   CS "../src/*.c")

set(SOURCES  ${CS}  client.c )

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

add_executable(${PROJECT_NAME} ${SOURCES})	
