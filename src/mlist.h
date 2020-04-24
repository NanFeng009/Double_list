#ifndef LIST_T_H
#define LIST_T_H

struct le {
    int key;
    struct le *prev;
    struct le *next;
};

struct list_t{
    struct le * nil;
};

void list_init(struct list_t *list);
void list_destroy(struct list_t *list);
void list_add(struct list_t *list, int key);
struct le * list_entry(struct list_t *list, int key);
void list_del(struct list_t *list, int key);
void list_foreach(struct list_t * list);
void list_add_tail(struct list_t *list, int key);

#endif
