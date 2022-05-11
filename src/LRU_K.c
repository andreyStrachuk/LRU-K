#include "LRU_K.h"

struct list_elem *update_head(struct List *cache, struct hash_map *hash_table,
                              int page, int len_cache) {
  struct list_elem *new_elem;
  new_elem = push_head(cache, page);
  if (cache->size > len_cache) {

    hash_table->hash_table[cache->tail->data].status = OUT; //!TO DO SetStatus
    delete_tail(cache);
  }
  return new_elem;
}

int LRU_step(struct List *cache, struct hash_map *hash_table, int page,
             int page_num, int len_cache) {

  if (check_if_in_hash_map(hash_table, page) == IN) {
    change_history(hash_table->hash_table[page].history, page_num, K);
    //! TO DO function update hash map:
    if (check_if_in_cache(hash_table, page) == IN) {
      insert_head(cache, hash_table->hash_table[page].cache_elem);
      return 1;
    } else {

      free(hash_table->hash_table[page].cache_elem);
      hash_table->hash_table[page].cache_elem =
          update_head(cache, hash_table, page, len_cache);
      return 0;
    }
  } else {
    struct list_elem *new_elem = update_head(cache, hash_table, page, len_cache);

    hash_map_insert(hash_table, page, page_num, IN, new_elem);
    return 0;
  }

  return 0;
}
