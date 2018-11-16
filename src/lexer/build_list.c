#include <fnmatch.h>
#include "list.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "build_list.h"

static enum token get_token(char *str)
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

static int open_file(char *path)
{
    int fd = open(path, O_RDWR);
    if (fd == -1)
    {
        fprintf(stderr, "42sh: %s: no such file or directory\n", path);
        return -1;
    }
    struct stat buff;
    fstat(fd, &buff);
    if (S_ISDIR(buff.st_mode))
    {
        fprintf(stderr, "%s: %s: is a directory\n", path, path);
        close(fd);
        return -1;
    }
    return fd;
}



void read_file(struct list *l, char *path)
{
    int fd = open_file(path);
    if (fd == -1)
        return;
    char buffer[4096] = {'0'};
    char str[4096] = {'0'};
    size_t i = 0;
    size_t j = 0;
    while (read(fd, buffer, 4096))
    {
        while (i < 4096 && buffer[i] != '\0')
        {
            if ((buffer[i] == ' ' || buffer[i] == '\n') && j == 0)
            {
                i++;
                continue;
            }
            else if (buffer[i] == ' ' || buffer[i] == '\n')
            {
                str[j] = '\0';
                size_t len = strlen(str) + 1;
                char *tok = malloc(sizeof(char) * len);
                if (!tok)
                    puts("shit");
                tok = strncpy(tok, str, len);
                list_add(l, get_token(tok), tok);
                j = 0;
            }
            else if (buffer[i] < 'a' && buffer[i] > 'z')
            {
                str[j] = '\0';
                size_t len = strlen(str) + 1;
                char *tok = malloc(sizeof(char) * len);
                if (!tok)
                    puts("shit");
                tok = strncpy(tok, str, len);
                list_add(l, get_token(tok), tok);
                char *single = malloc(sizeof(char) * 2);
                single = strncpy(single, ";\0", 2);
                list_add(l, get_token(single), single);
                j = 0;
            }
            else
            {
                str[j] = buffer[i];
                j++;
            }
            i++;
        }
        i = 0;
        j = 0;
    }
    close(fd);
}
