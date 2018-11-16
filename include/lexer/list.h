/*!
 * \file list.h
 * \brief Linked List
 * \author Jean-Louis UNG / Tristan MARTIN
 */

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

/*!
 * \enum token
 * \brief Enum Token
 */

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
    PIPE,
    DOLLAR,
    L_RAFT,
    R_RAFT,
    L_PARENTHESE,
    R_PARENTHESE,
    NONE
};

/*!
 * \struct list_elt
 * \brief Struct list_elt
 */
struct list_elt
{
    enum token t;
    char *strtoken;
    struct list_elt *next;
};

/*!
 * \struct list
 * \brief Struct list containing struct list_elt
 */
struct list
{
    size_t size;
    struct list_elt *head;
};

/*!
 * \fn struct list *list_init(void)

 * \brief Initialize a new instance of the struct list and return a pointer.

 * \return Returns a new pointer on a new instance of struct list. On error,
    returns NULL.
 */
struct list *list_init(void);

/*!
 * \fn void list_add(struct list *l, enum token t, char *str)
 * \brief Insert a struct list_elt containing t and str at the head of the
 * list.

 * \param l: The struct list where it inserts.
 * \param t: The enum token added to the struct list_elt.
 * \param str: The char *str added to the struct list_elt.

 * \return Returns no value.

 */
void list_add(struct list *l, enum token t, char *str);

/*!
 * \fn struct list_elt *list_pop(struct list *l)
 * \brief Pop the struct list_elt at the end of list.

 * \param l: The struct list where to pop.

 * \return Returns a new pointer pointing at the popped struct list_elt. On
 * error, returns NULL.
 */
struct list_elt *list_pop(struct list *l);

/*!
 * \fn void list_destroy(struct list *l)
 * \brief Destroy the list by freeing all its element.

 * \param l: The struct list to be destroyed.

 * \return Returns no value.
 */
void list_destroy(struct list *l);

/*!
 * \fn void list_print(struct list *l)

 * \brief Print l.
 * \param l: The struct list to be printed.
 * \return Returns no value.
 */
void list_print(struct list *l);

#endif /* ! LIST_H */
