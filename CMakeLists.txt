project (clang++)

cmake_minimum_required(VERSION 2.8)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules/")

add_definitions (-Wall -Wextra -Werror -std=c++11)

if ("${CMAKE_BUILD_TYPE}" STREQUAL Release)
  add_definitions (-O3)
else ("${CMAKE_BUILD_TYPE}" STREQUAL Release)
  add_definitions (-g3 -ggdb -Og)
endif ("${CMAKE_BUILD_TYPE}" STREQUAL Release)

find_package (Libclang REQUIRED)

add_library (clang++
	index.cpp
	translationunit.cpp
	cursor.cpp
	sourcelocation.cpp
	sourcerange.cpp
	string.cpp
	token.cpp
	tokens.cpp
	file.cpp
	)

target_link_libraries (clang++ ${Libclang_LIBRARIES})
include_directories (${Libclang_INCLUDE_DIRS})
include_directories (${CMAKE_CURRENT_LIST_DIR}/..)
