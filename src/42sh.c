#include <fnmatch.h>
#include "list.h"
#include "options.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "build_list.h"

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
    argc = argc;
    if (argv[1][0] != '-')
        read_file(l, argv[1]);
        //run file
    else if (!fnmatch("--version", argv[1], 0) || !fnmatch("-v", argv[1], 0))
        fprintf(stderr, "Version 0.3\n");
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
    //list_print(l);
    list_destroy(l);
    return 0;
}
