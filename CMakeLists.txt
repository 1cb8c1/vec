cmake_minimum_required(VERSION 3.31)
project(vec C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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
	-Wpedantic
)

add_library(vec STATIC
	src/vector.c
	src/vmath.c
)

set_target_properties(vec PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
)

target_include_directories(vec PUBLIC ${PROJECT_SOURCE_DIR}/include)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(vec PUBLIC ${COMMON_WARN_FLAGS})
endif()


# Testing
enable_testing()
add_executable(vec_tests tests/vector.spec.c)
target_include_directories(vec_tests PRIVATE include)
target_link_libraries(vec_tests PRIVATE vec)
add_test(NAME vec_tests COMMAND vec_tests)
