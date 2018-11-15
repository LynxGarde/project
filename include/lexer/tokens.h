#ifndef TOKENS_H
#define TOKENS_H

#include <stdio.h>
#include <stdlib.h>

enum token
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
    R_BRACES,

    NONE
};

struct list_elt
{
    enum token t;
    struct list_elt *next;
};

struct list
{
    size_t size;
    struct list_elt *head;
};

#endif /* ! TOKENS_H */
