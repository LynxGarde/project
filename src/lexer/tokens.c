#include "../../include/lexer/tokens.h"

struct list *list_init(void)
{
    struct list *l = malloc(sizeof(struct list));
    if (!l)
        return NULL;
    l->head = NULL;
    return l;
}

struct list_elt *list_add(struct list *l, enum token t)
{
    if (!l)
        return NULL;
    struct list_elt *new = malloc(sizeof(struct list_elt));
    if (!new)
        return NULL;
    new->t = t;
    new->next = l->head;
    l->head = new;
    return new;
}

enum token list_pop(struct list *l)
{
    if (!l || !l->head)
        return NONE;
    struct list_elt *tmp = l->head;
    if (!l->head->next)
    {
        enum token t = l->head->t;
        free(l->head);
        l->head = NULL;
        return t;
    }
    while (tmp->next->next)
        tmp = tmp->next;
    struct list_elt *pop = tmp->next;
    tmp->next = NULL;
    enum token t = pop->t;
    free(pop);
    return t;
}

void elt_destroy(struct list_elt *elt)
{
    if (elt->next)
        elt_destroy(elt);
    free(elt);
}

void list_destroy(struct list *l)
{
    struct list_elt *elt = l->head;
    if (elt)
        elt_destroy(elt);
    free(l);
}

void list_print(struct list *l)
{
    struct list_elt *tmp = l->head;
    for (int i = 0; tmp; i++)
    {
        printf("%d ", tmp->t);
        tmp = tmp->next;
    }
    printf("\n");
}
/*
int main(void)
{
    struct list *l = list_init();
    list_add(l, IF);
    list_add(l, CMD);
    list_add(l, L_AND);
    list_add(l, CMD);
    list_add(l, SEMICOLON);
    list_add(l, THEN);
    list_add(l, CMD);
    list_add(l, SEMICOLON);
    list_add(l, ELSE);
    list_add(l, CMD);
    list_add(l, SEMICOLON);
    list_add(l, FI);
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_destroy(l);
    return 0;
}*/
