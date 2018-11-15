include_directories(../../include/parser)

add_library(parser options.c)
target_include_directories(parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
