cmake_minimum_required(VERSION 3.31)
project(vec C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER "gcc")

set(COMMON_WARN_FLAGS
	# Defensive flags (for safer code)
	-Wall
	-Wextra
	-Wconversion
	-Werror
	-Wshadow
	-Wpointer-arith
	-Wcast-align
	-Wstrict-prototypes
	-Wmissing-prototypes
	-Wredundant-decls
	-Wold-style-definition
	-Wformat=2
	-Wundef
	-Wunreachable-code
	-Wnull-dereference
	-Wdouble-promotion
	-Wsign-conversion
	-Wvla
	-pedantic-errors
)


add_library(vec STATIC src/vector.c)
target_include_directories(vec PUBLIC ${PROJECT_SOURCE_DIR}/include)




