add_subdirectory(lexer) #lexer
add_subdirectory(parser) #parser


include_directories(../include/lexer
                    ../include/parser
) #path to include dir

add_executable(42sh 42sh.c) #create binary from 42sh.c
target_link_libraries(42sh PRIVATE lexer parser) #add parser lexer
