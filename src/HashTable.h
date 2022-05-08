#ifndef HASHTABLE
#define HASHTABLE

#include "Doubly_connected_list.h"
#include <ctype.h>
#include <string.h>

#define K 3

enum ERRORS {
  RECREATING_LIST,
  NULLPTR,
  OK,
  WRONGINDEX,
  NOTHINGTOREMOVE,
  WRONGSIZE,
  WRONGTAIL,
  WRONGHEAD,
  WRONGFREEHEAD,
  LISTISDAMAGED,
  ALLOC_FAILED,
  UNABLETOOPENFILE,
  NOARGUMENTS
};

enum Status { OFF, ON, OUT, IN };

struct hash_map {
  int capacity;
  int size;

  struct hash_elem *hash_table;
};

struct hash_elem {
  enum Status status;

  struct list_elem *cache_elem;

  struct List *history;
};

int hash_map_construct(struct hash_map *table, const int size);

int hash_map_destruct(struct hash_map *table);

int hash_map_resize_up(struct hash_map *table);

int hash_map_insert(struct hash_map *table, int value, int time, int status,
                    struct list_elem *cache_elem);

int SetStatus(struct hash_elem *el, int st);

int check_if_in_hash_map(struct hash_map *table, int value);

int change_history(struct List *list, int time, int k);

int check_if_in_cache(struct hash_map *table, const int value);

#endif
