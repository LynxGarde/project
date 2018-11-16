/*!
 * \file ast_t.h
 * \brief Abstract Syntax Tree
 * \author Leo TORDJMAN
 */
#pragma once

#include "list.h"

/*!
 * \struct key
 * \brief Struct key
 */
struct key
{
    enum token t;
    char *str;
};

/*!
 * \struct ast_t
 * \brief Struct ast_t
 */
struct ast_t
{
    struct key key;
    struct ast_t *cond;
    struct ast_t *if_true;
    struct ast_t *if_false;
};

/*!
 * \fn struct ast_t *ast_init(struct key key,
    struct ast_t *cond, struct ast_t *if_true, struct ast_t *if_false)

 * \brief Initialize a new instance of the struct ast_t and return a pointer.

 * \param key: value of current node.
 * \param cond: node condition.
 * \param if_true: node if condition returns true.
 * \param if_false: node if condition returns false.

 * \return Returns a new pointer on a new instance of struct ast_t. On error,
    returns NULL.
 */
struct ast_t *ast_init(struct key key,
    struct ast_t *cond, struct ast_t *if_true, struct ast_t *if_false);

/*!
 * \fn void ast_delete(struct ast_t *ast)
 * \brief Free the given ast.

 * \param ast: ast to free.

 * \return Returns a new pointer on a new instance of struct ast_t. On error,
    returns NULL.
 */
void ast_delete(struct ast_t *ast);

/*!
 * \fn struct ast_t *ast_build(struct ast_t *ast, struct list *l)
 * \brief Build an AST from the given list.

 * \param ast: The AST to build;
 * \param list: The list from which the AST will be built.

 * \return Returns a new pointer on a new instance of struct ast_t. On error,
    returns NULL.
 */
struct ast_t *ast_build(struct ast_t *ast, struct list *l);
