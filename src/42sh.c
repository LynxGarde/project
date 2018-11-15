#include <fnmatch.h>
#include "list.h"
#include "options.h"

/*
static struct option long_options[] =
{
    {"version", no_argument, 0, 'v'},
    {"ast-print", no_argument, 0, 'a'},
    {"norc", no_argument, 0, 'n'},
    {NULL, 0, NULL, 0}
};
*/

void read_file(struct list *l, char *path)
{
    FILE *f = fopen(path, "r");
    if (!f)
        return;
    l = l;
}

void separate(struct list *l, int argc, char *argv[])
{
    l = l;
    argc = argc;
    if (argv[1][0] != '-')
        puts("file");
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
    list_destroy(l);
    return 0;
}
