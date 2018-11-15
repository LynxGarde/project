#include <fnmatch.h>
#include "tokens.h"

/*
static struct option long_options[] =
{
    {"version", no_argument, 0, 'v'},
    {"ast-print", no_argument, 0, 'a'},
    {"norc", no_argument, 0, 'n'},
    {NULL, 0, NULL, 0}
};
*/

void separate(struct list *l, int argc, char *argv[])
{
    l = l;
    argc = argc;
    if (!fnmatch("--version", argv[1], 0))
        puts("Version 0.01");
    else if (!fnmatch("--norc", argv[1], 0))
        puts("--norc");
        //fix it with how to deactivate the resources headers
    else if (!fnmatch("--ast-print", argv[1], 0))
        puts("--ast-print");
        //fix it with the parser
    else if (!fnmatch("-O", argv[1], 0) || !fnmatch("+O", argv[1], 0))
        puts("-O or +O");
        //Call the func and check if -O or +O
    else if (!fnmatch("-c", argv[1], 0))
        puts("-c");
        //run the cmd with ast
    else
        puts("JCPas");
        //run file

}

int main(int argc, char *argv[])
{
    struct list *l = list_init();
    if (argc == 1)
        return 0;
    separate(l, argc, argv);
    return 0;
}
