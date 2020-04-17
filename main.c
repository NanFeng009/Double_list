#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_t.h"

int main()
{
    struct list_t *mydict = (struct list_t *)malloc(sizeof(struct list_t));
    list_init(mydict);
    list_prepend(mydict, 2);
    list_prepend(mydict, 3);
    list_prepend(mydict, 4);
    struct le *tmp = list_search(mydict, 3);
    printf("%d\t", tmp->key);
    printf("\n");
    list_foreach(mydict);
    list_delete(mydict, 3);
    list_foreach(mydict);
    list_prepend(mydict, 8);
    list_foreach(mydict);

    return 0;
}

