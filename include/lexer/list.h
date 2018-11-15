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
    char *strtoken;
    struct list_elt *next;
};

struct list
{
    size_t size;
    struct list_elt *head;
    struct list_elt *iterator;
};

struct list *list_init(void);
void list_add(struct list *l, enum token t, char *str);
struct list_elt *list_pop(struct list *l);
void elt_destroy(struct list_elt *elt);
void list_destroy(struct list *l);
void list_print(struct list *l);

#endif /* ! TOKENS_H */
