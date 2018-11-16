include_directories(../../include/lexer)
include_directories(../../include/parser)

add_library(parser ast_t.c options.c)
target_include_directories(parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
