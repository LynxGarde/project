/*!
 * \file options.h
 * \brief Options Error Handler
 * \authors Tristan MARTIN
 */

#ifndef OPTIONS_H
#define OPTIONS_H

/*!
 * \fn void error_helper(char *str)

 * \brief Prints an error message depending on str.

 * \param str: The string to be checked.

 * \return Returns no value.
 */
void error_helper(char *str);
/*!
 * \fn void command(int argc, char *argv[])

 * \brief Prints an error message depending on the number of arguments.

 * \param argc: The number of arguments.

 * \param argv: The arguments given by the input

 * \return Returns no value.
 */
void command(int argc, char *argv[]);

#endif /* ! OPTIONS_H */
