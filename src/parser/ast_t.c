#include <stdlib.h>

#include "ast_t.h"

struct ast_t *ast_init(char *key, struct ast_t *child, struct ast_t *sibling)
{
    struct ast_t *ast = malloc(sizeof(struct ast_t));
    if (!ast)
        return NULL;
    ast->key = key;
    ast->child = child;
    ast->sibling = sibling;
    return ast;
}

void ast_delete(struct ast_t *ast)
{
    if (ast)
    {
        if (ast->child)
            ast_delete(ast->child);
        if (ast->sibling)
            ast_delete(ast->sibling);
        free(ast);
    }
}
