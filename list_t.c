#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_t.h"



void list_init(struct list_t *list) {
    list->nil.key = 0;
    list->nil.prev = &(list->nil);
    list->nil.next = &(list->nil);
}

void list_destroy(struct list_t *list) {
    struct le *node = list->nil.next;
    struct le *next;
    
    while (node != &(list->nil)) {
        next = node->next;
        free(node);
        node = next;
    }
}

void list_prepend(struct list_t *list, int key) {
    struct le *newnode = (struct le *) malloc(sizeof(struct le));
    newnode->key = key;
    newnode->next = list->nil.next;
    list->nil.next->prev = newnode;
    list->nil.next = newnode;
    newnode->prev = &list->nil;
}

struct le * list_search(struct list_t *list, int key) {
    struct le *node = list->nil.next;
    
    while (node != &list->nil && node->key != key) {
        node = node->next;
    }
    
    if (node == &(list->nil)) {
        return NULL;
    } else {
        return node;
    }
}

void list_delete(struct list_t *list, int key) {
	struct le *node = list_search(list, key);
	if (node == NULL)
		return;

	node->prev->next = node->next;
	node->next->prev = node->prev;
}

void list_foreach(struct list_t * list)
{
    struct le *node = list->nil.next;
    
	while (node != &list->nil) {
		printf("%d\t", node->key);
		node = node->next;
	}
	printf("\n");

}
