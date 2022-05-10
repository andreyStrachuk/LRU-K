#ifndef LRU_K_H_INCLUDED
#define LRU_K_H_INCLUDED

#include "Doubly_connected_list.h"
#include "HashTable.h"

int LRU_step(struct List *cache, struct hash_map *hash_table, int page,
             int page_num, int len_cache);

#endif // LRU_K_H_INCLUDED
