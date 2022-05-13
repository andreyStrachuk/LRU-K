#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LRU_K.h"

#define relative_hash_table_size 0.1

int read_number(int *number);

int main() {
  clock_t start, end;
  int len_cache, number_pages, len_hash_table, page, maxpage, hits;
  struct list_LRU *cache;
  struct hash_map *table =
      (struct hash_map* )calloc(1, sizeof(struct hash_map));
  hits = 0;
  maxpage = 0;

  read_number(&len_cache);
  read_number(&number_pages);
  len_hash_table = relative_hash_table_size * number_pages;

  cache = create_list_LRU();
  hash_map_construct(table, 10);
  // printf("%d", hash_table.capacity);

  start = clock();

  for (int count_pages = 0; count_pages < number_pages; count_pages++) {
    read_number(&page);
    if (page > maxpage)
    {
      maxpage = page;
    }

    hits += LRU_step(cache, table, page, count_pages, len_cache);
    //print_list(cache->list);
  }

  end = clock();
  printf("Working hours: %f\n", difftime(end, start) / (CLOCKS_PER_SEC));

  printf("Hits: %d\n", hits);
  printf("Probability of hitting the cache: %f\n", (float)hits / (number_pages - maxpage));

  destruct_list_LRU(cache);
  // hash_map_destruct(table);

  return 0;
}

int read_number(int *number) {
  int scan;

  scan = scanf("%d", number);

  assert(scan && "Input Error");

  if ((*number) < 0) {
    scan = 0;
    assert(scan && "Wrong format");
  }

  return 0;
}
