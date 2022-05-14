#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "LRU_K.h"

int main() {
  int hits;

  hits = lru_k();

  printf("%d", hits);

  return 0;
}
