#ifndef HASH_T_H
#define HASH_T_H
#include "mlist.h"
#include <stdint.h>

/** Defines a hashmap table */
struct hash_t {
    struct list_t *bucket;  /**< Bucket with linked lists */
    uint32_t bsize;       /**< Bucket size              */
};

int hash_init(struct hash_t **hp, uint32_t bsize);
void hash_add(struct hash_t *h, uint32_t key);
void hash_del(struct hash_t *h, uint32_t key);
struct le * hash_entry(struct hash_t *h, uint32_t key);
void hash_foreach(struct hash_t *h);
void hash_destory(struct hash_t *h);
#endif
