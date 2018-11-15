#include "tokens.h"

void error_helper(char *str)
{
    printf("./42sh: --%s: invalid option\n", str);
    printf("Usage:	bash [GNU long option] [option] ...\n");
    printf("\tbash [GNU long option] [option] script-file ...\n");
    printf("GNU long options:\n");
    printf("\t--version\n");
    printf("\t--norc\n");
    printf("\t--ast-print\n");
    printf("Shell options:\n");
    printf("\t-c command or -O\n");
}


