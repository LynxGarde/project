#include <tokens.h>

int main(void)
{
    struct list *l = list_init();
    list_add(l, IF);
    list_add(l, CMD);
    list_add(l, L_AND);
    list_add(l, CMD);
    list_add(l, SEMICOLON);
    list_add(l, THEN);
    list_add(l, CMD);
    list_add(l, SEMICOLON);
    list_add(l, ELSE);
    list_add(l, CMD);
    list_add(l, SEMICOLON);
    list_add(l, FI);
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_print(l);
    printf("ENUM_pop: %d\n", list_pop(l));
    list_destroy(l);
    return 0;
}
