#ifndef HASHTABLE
#define HASHTABLE

#include "Doubly_connected_list.h"
#include <string.h>
#include <ctype.h>

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

enum Status {
    OFF,
    ON
};

struct HashTable {
    int size;

    struct hash_elem *hash_table;
};

struct history_elem {

    int time_call;

    struct history_elem *next;

};

struct hash_elem {

    enum Status status;

    struct list_elem *cache_elem;
    struct List *history;

};


int HashTableInit (struct HashTable *table, const int size);

int HashTableDestruct (struct HashTable *table);

int HashTableInsert (struct HashTable *table, int value);

int HashCRC32 (struct HashTable *table, void *val);

int HashTableSearch (struct HashTable *table, int value);

int SetStatus (struct hash_elem *el, Status st);


#endif
