#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mlist.h"
#include "mhash.h"

int main()
{
	printf("################  list test ###############\n");
    struct list_t *mydict = (struct list_t *)malloc(sizeof(struct list_t));
    list_init(mydict);
    list_add(mydict, 2);
    list_add(mydict, 3);
    list_add(mydict, 4);
    list_foreach(mydict);
    list_del(mydict, 3);
    list_del(mydict, 30);
    list_foreach(mydict);
    list_add(mydict, 8);
    list_foreach(mydict);
	list_add_tail(mydict, 20);
    list_foreach(mydict);
	list_destroy(mydict);

	printf("################  hash test ###############\n");
	struct hash_t *myhash;
	hash_init(&myhash, 5);

	for(int i = 0; i < 20; i++)
		hash_add(myhash, i);

	hash_foreach(myhash);
	hash_del(myhash, 6);
	hash_del(myhash, 18);
	hash_del(myhash, 10);
	hash_del(myhash, 2);
	hash_del(myhash, 14);
	printf("-----------\n");
	hash_foreach(myhash);
	 hash_destory(myhash);
    return 0;
}

