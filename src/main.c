#include "LRU_K.h"

#define relative_hash_table_size 0.1

int read_number(int *number);

int main() {
    int len_cache, number_pages, page, hits = 0;
    struct list_LRU *cache;
    struct hash_map *table =
        (struct hash_map *)calloc(1, sizeof(struct hash_map));

    read_number(&len_cache);
    read_number(&number_pages);

    cache = create_list_LRU();
    hash_map_construct(table, 10);

    for (int count_pages = 0; count_pages < number_pages; count_pages++) {
        read_number(&page);

        hits += LRU_step(cache, table, page, count_pages, len_cache);
    }

    printf("%d\n", hits);

    destruct_list_LRU(cache);
    hash_map_destruct(table);

    free (table);

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
