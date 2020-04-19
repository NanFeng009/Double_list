#include "hash_t.h"
#include "list_t.h"
#include <stdlib.h>

#define NUM_BUCKETS 10

// Djb2 hash function
unsigned long hash_djb2(char *str) {

        unsigned long hash = 5381;
        int c;
        while ((c = *str++))
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        return hash % NUM_BUCKETS;
}
/**
 * Init a new hashmap table
 *
 * @param hp     Address of hashmap pointer
 * @param bsize  Bucket size
 *
 * @return 0 if success, otherwise errorcode
 */
int hash_init(struct hash_t **hp, uint32_t bsize)
{
	struct hash_t *h;

	if (!hp || !bsize)
		return -1;


	h = (struct hash_t *)malloc(sizeof(struct hash_t));
	if (!h)
		return -1;

	h->bsize = bsize;

	h->bucket = (struct list_t *)malloc(bsize*sizeof(struct list_t));
	if (!h->bucket) 
		return -1;

	for(int i = 0; i < bsize; i++){
		list_init(h->bucket + i);
	}

	*hp = h;

	return 0;
}

/**
 * Add an element to the hashmap table
 *
 * @param h      Hashmap table
 * @param le     List element
 */
void hash_append(struct hash_t *h, uint32_t key)
{
    if (!h)
        return;

	// append the key to the tail of list
    //list_append(h->bucket + (key % (h->bsize-1)) , key);
    list_prepend(h->bucket + (key % (h->bsize-1)) , key);
}


/**
 * Delete an element from the hashmap table
 *
 * @param le     List element
 */
void hash_delete(struct hash_t *h, uint32_t key)
{
    if (!h)
        return;

    list_delete((h->bucket) + (key % (h->bsize-1)), key);
}


struct le * hash_search(struct hash_t *h, uint32_t key)
{
	if (!h)
		return NULL;

	struct le *node;
	node = list_search((h->bucket) + (key % (h->bsize-1)), key);

	return node;

}

void hash_foreach(struct hash_t *h)
{
	if (!h)
		return;

	for(int i = 0; i < h->bsize; i++){
		list_foreach(h->bucket + i);
	}

	return;
}

void hash_destory(struct hash_t *h)
{
	if (!h)
		return;

	for(int i = 0; i < h->bsize; i++){
		list_destroy(h->bucket + i);
	}

	return;

}
