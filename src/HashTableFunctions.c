#include "HashTable.h"

const int capacity = 50;

int hash_map_construct (struct hash_map *table, const int capacity) {
    assert (table);

    table->capacity = capacity;
    table->size = 0;

    table->hash_table = (struct hash_elem *)calloc (capacity, sizeof (struct hash_elem));
    if (table->hash_table == NULL) return ALLOC_FAILED;

    return OK;
}

int SetStatus (struct hash_elem *el, int st) {
    assert (el);

    el->status = st;

    return OK;
}

int hash_map_destruct (struct hash_map *table) {
    assert (table);

    for (int i = 0; i < table->size; i++) {
        delete_list (table->hash_table[i].history);
    }

    free (table->hash_table);

    return OK;
}

int hash_map_insert (struct hash_map *table, int value, int time, int status, struct list_elem *cache_elem) {
    assert (table);

    if (table->size == table->capacity - 1 || value >= table->capacity) {
        hash_map_resize_up (table);
    }

    create_list (table->hash_table[value].history);
    push_tail (table->hash_table[value].history, time);
    table->hash_table[value].status = status;
    table->hash_table->cache_elem = cache_elem;
    table->size++;

    return OK;
}

int hash_map_resize_up (struct hash_map *table) {
    assert (table);

    void *ptr = realloc (table->hash_table, table->capacity * 2 * sizeof (struct hash_elem *));
    if (ptr == NULL) return ALLOC_FAILED;

    table->hash_table = (struct hash_elem *)ptr;
    table->capacity *= 2;

    return OK;
}

int check_in_hash_map (struct hash_map *table, int value) {
    assert (table);

    if (value >= capacity) return OUT;

    if (table->hash_table[value].history->size == 0) return OUT;

    return IN;
}

int main () {
    struct hash_map *table = (struct hash_map *)calloc (1, sizeof (struct hash_map));

    hash_map_construct (table, capacity);

    hash_map_destruct (table);

    free (table);

    return 0 ;
}