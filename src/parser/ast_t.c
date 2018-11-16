#include <stdlib.h>

#include "ast_t.h"

struct ast_t *ast_init(struct key key,
    struct ast_t *cond, struct ast_t *if_true, struct ast_t *if_false)
{
    struct ast_t *ast = malloc(sizeof(struct ast_t));
    if (!ast)
        return NULL;
    ast->key = key;
    ast->cond = cond;
    ast->if_true = if_true;
    ast->if_false = if_false;
    return ast;
}

void ast_delete(struct ast_t *ast)
{
    if (ast)
    {
        if (ast->cond)
            ast_delete(ast->cond);
        if (ast->if_true)
            ast_delete(ast->if_true);
        if (ast->if_false)
            ast_delete(ast->if_false);
        free(ast);
    }
}

struct ast_t *ast_build(struct ast_t *ast, struct list *l)
{
    if (!l)
        return NULL;
    if (!l->head)
    {
        list_destroy(l); //This list cannot be reused.
        return ast;
    }
    struct list_elt *elt = list_pop(l);
    struct key key;
    key.t = elt->t;
    key.str = elt->strtoken;
    free(elt);
    if (key.t == IF)
        return NULL;
    return NULL;
}
