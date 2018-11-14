#ifndef TOKENS_H
#define TOKENS_H

#include <stdio.h>
#include <stdlib.h>

struct list
{
    enum token_t *t;
    struct list *next;
    size_t size;
};

enum token_t
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
    SEMICOLON,
    L_BRACES,
    R_BRACES
};

#endif /* ! TOKENS_H */
