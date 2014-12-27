cmake_minimum_required(VERSION 2.6)

project(csv-parser-sample CXX)

set(project_exec "csv-parser-sample")

set(lib_dir "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(src_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -std=c++11")

include_directories(${lib_dir})

set(src_files
	${src_dir}/dummy_data_line.cpp
	${src_dir}/main.cpp
)

set(all_libs
	"pthread"
)

add_executable(${project_exec} ${src_files})
target_link_libraries(${project_exec} ${all_libs})
