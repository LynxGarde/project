cmake_minimum_required(VERSION 3.0)
project(my_read_iso LANGUAGES C)
add_compile_options(-Wall -Werror -Wextra -std=c99 -pedantic)

add_subdirectory(src/)
