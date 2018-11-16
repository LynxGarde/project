/*!
 * \file build_list.h
 * \brief Build List from input file
 * \author Jean-Louis UNG / Tristan MARTIN
 */
#ifndef BUILD_LIST_H
#define BUILD_LIST_H

/*!
 * \fn void read_file(struct list *l, char *path)

 * \brief Read from path and split into the list l.

 * \param l: The list where the string are added.
 * \param path: The path of the file to read.

 * \return Returns no value.
 */
void read_file(struct list *l, char *path);

#endif /* ! BUILD_LIST_H */
