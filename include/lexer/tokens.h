#ifndef TOKENS_H
#define TOKENS_H

#include <stdio.h>
#include <stdlib.h>

struct tokens
{
    enum token_type *t;
};

enum token_type
{
    IF = 1,
    THEN,
    FI,
    ELSE,
    WHILE,
    FOR,
    DO,
    DONE,
    CMD,
    L_OR,
    L_AND,
    SEMICOLON
};

#endif /* ! TOKENS_H */
