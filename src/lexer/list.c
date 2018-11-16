#include "list.h"

struct list *list_init(void)
{
    struct list *l = malloc(sizeof(struct list));
    if (!l)
        return NULL;
    l->head = NULL;
    return l;
}

void list_add(struct list *l, enum token t, char *str)
{
    if (!l)
        return;
    struct list_elt *new = malloc(sizeof(struct list_elt));
    if (!new)
        return;
    new->t = t;
    new->strtoken = str;
    new->next = l->head;
    l->head = new;
}

struct list_elt *list_pop(struct list *l)
{
    if (!l || !l->head)
        return NULL;
    struct list_elt *tmp = l->head;
    if (!l->head->next)
    {
        struct list_elt *elt = l->head;
        l->head = NULL;
        return elt;
    }
    while (tmp->next->next)
        tmp = tmp->next;
    struct list_elt *pop = tmp->next;
    tmp->next = NULL;
    return pop;
}

void elt_destroy(struct list_elt *elt)
{
    if (elt->next)
        elt_destroy(elt->next);
    free(elt->strtoken);
    free(elt);
}

void list_destroy(struct list *l)
{
    if (!l)
        return;
    struct list_elt *elt = l->head;
    if (elt)
        elt_destroy(elt);
    free(l);
}

void list_print(struct list *l)
{
    struct list_elt *tmp = l->head;
    puts("head");
    for (int i = 0; tmp; i++)
    {
        printf("strtoken: %s %d\n", tmp->strtoken, tmp->t);
        tmp = tmp->next;
    }
}
