#include <fnmatch.h>
#include "list.h"
#include "options.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/*
static struct option long_options[] =
{
    {"version", no_argument, 0, 'v'},
    {"ast-print", no_argument, 0, 'a'},
    {"norc", no_argument, 0, 'n'},
    {NULL, 0, NULL, 0}
};
*/

enum token get_token(char *str)
{
    if (strncmp(str, "if", 2) == 0)
        return IF;
    else if (strncmp(str, "then", 4) == 0)
        return THEN;
    else if (strncmp(str, "fi", 2) == 0)
        return FI;
    else if (strncmp(str, "else", 4) == 0)
        return ELSE;
    else if (strncmp(str, "while", 5) == 0)
        return WHILE;
    else if (strncmp(str, "for", 3) == 0)
        return FOR;
    else if (strncmp(str, "do", 2) == 0)
        return DO;
    else if (strncmp(str, "done", 4) == 0)
        return DONE;
    else if (strncmp(str, "||", 2) == 0)
        return L_OR;
    else if (strncmp(str, "&&", 2) == 0)
        return L_AND;
    else if (strncmp(str, ";", 1) == 0)
        return SEMICOLON;
    else if (strncmp(str, "{", 1) == 0)
        return L_BRACES;
    else if (strncmp(str, "}", 1) == 0)
        return R_BRACES;
    else
        return CMD;
}

void read_file(struct list *l, char *path)
{
    int fd = open(path, O_RDWR);
    if (fd == -1)
    {
        fprintf(stderr, "42sh: %s: no such file or directory\n", path);
        return;
    }
    struct stat buff;
    fstat(fd, &buff);
    if (S_ISDIR(buff.st_mode))
    {
        fprintf(stderr, "%s: %s: is a directory\n", path, path);
        close(fd);
        return;
    }
    char buffer[4096];
    size_t len = 0;
    char *copy = NULL;
    while (read(fd, buffer, 4096))
    {
        char *s = strtok(buffer, " \n");
        while (s)
        {
            len = strlen(s);
            if (s[len - 1] == ';')
            {
                copy = malloc(sizeof(char) * len);
                copy = strncpy(copy, s, len - 1);
                list_add(l, get_token(copy), copy);
                list_add(l, get_token(";"), ";");
                s = strtok(NULL, " \n");
            }
            list_add(l, get_token(s), s);
            s = strtok(NULL, " \n");
        }
    }
    close(fd);
}

void separate(struct list *l, int argc, char *argv[])
{
    l = l;
    argc = argc;
    if (argv[1][0] != '-')
        read_file(l, argv[1]);
        //run file
    else if (!fnmatch("--version", argv[1], 0) || !fnmatch("-v", argv[1], 0))
        puts("Version 0.01");
    else if (!fnmatch("--norc", argv[1], 0) || !fnmatch("-n", argv[1], 0))
        puts("--norc");
        //fix it with how to deactivate the resources headers
        //fix multiple options
    else if (!fnmatch("--ast-print", argv[1], 0) || !fnmatch("-a", argv[1], 0))
        puts("--ast-print");
        //fix it with the parser
    else if (!fnmatch("-O", argv[1], 0) || !fnmatch("+O", argv[1], 0))
        puts("-O or +O");
        //Call the func and check if -O or +O
        //fix -O or +O stick with something else just behind it (works for O)
    else if (!fnmatch("-c", argv[1], 0))
        puts("-c");
        //run the cmd with ast
    else
        error_helper(argv[1]);
        //run file
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        return 0;
    struct list *l = list_init();
    separate(l, argc, argv);
    list_print(l);
    list_destroy(l);
    return 0;
}
