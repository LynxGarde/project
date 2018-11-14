/**
 * \file ast.h
 * \brief Abstract Syntax Tree
 * \author Leo TORDJMAN
 */
#pragma once

/**
 * \struct ast_t
 * \brief Struct ast_t
 */
struct ast_t
{
    char *key;
    struct ast_t *child;
    struct ast_t *sibling;
};

/**
 * \fn struct ast_t *ast_init(char *key, struct ast_t *child,
 * struct ast_t *sibling)
 *
 * \brief Initialize a new instance of the struct ast_t and return a pointer.
 *
 * \param key: value of current node
 * \param child: first child
 * \param sibling: first sibling
 *
 * \return Returns a new pointer on a new instance of struct ast_t. On error,
 * returns NULL;
 */
struct ast_t *ast_init(char *key, struct ast_t *child, struct ast_t *sibling);

/**
 * \fn void ast_delete(struct ast_t *ast)
 *
 * \brief Free the given ast.
 *
 * \param ast: ast to free
 *
 * \return Returns a new pointer on a new instance of struct ast_t. On error,
 * returns NULL;
 */
void ast_delete(struct ast_t *ast);
