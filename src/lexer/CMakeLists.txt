include_directories(../../include/lexer) #path to include

add_library(lexer tokens.c)
target_include_directories(lexer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
