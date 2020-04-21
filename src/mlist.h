#ifndef LIST_T_H
#define LIST_T_H

struct le {
    int key;
    struct le *prev;
    struct le *next;
    struct le *hash_next;
};

struct list_t{
    struct le * nil;
};

void list_init(struct list_t *list);
void list_destroy(struct list_t *list);
void list_prepend(struct list_t *list, int key);
struct le * list_search(struct list_t *list, int key);
void list_delete(struct list_t *list, int key);
void list_foreach(struct list_t * list);
void list_append(struct list_t *list, int key);

#endif
