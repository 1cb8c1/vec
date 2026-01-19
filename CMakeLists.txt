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
	# -Wpedantic # Turned off to allow GNU extensions.
)

add_library(vec STATIC src/vector.c)

set_target_properties(vec PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
)

target_include_directories(vec PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_options(vec PUBLIC ${COMMON_WARN_FLAGS} -std=gnu23)
target_link_libraries(vec PUBLIC m)

# Testing
enable_testing()
add_executable(vec_tests tests/vector.spec.c)
target_link_libraries(vec_tests PRIVATE vec m)
target_include_directories(vec_tests PRIVATE include)
add_test(NAME vec_tests COMMAND vec_tests)
