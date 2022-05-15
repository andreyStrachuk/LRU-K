#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "LRU_K.h"

#define K 2

int main() {
  int hits, len_cache, number_pages;

  read_number(&len_cache);
  read_number(&number_pages);

  hits = lru_k(len_cache, number_pages, K);

  printf("%d\n", hits);


  return 0;
}
