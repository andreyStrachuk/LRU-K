#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Doubly_connected_list.h "
#include "HashTable.h"
#include "LRU_K.h"

#define K 1
#define relative_hash_table_size 0.1


int read_number(int *number);


int main()
{
	int len_cache, len_hash_table, number_pages, page, hits;
	struct List cache;
	struct hash_map hash_table;
	hits = 0;

	read_number(&len_cache);
	read_number(&number_pages);
	len_hash_table = relative_hash_table_size * number_pages;

	create_list(&cache);
	hash_map_construct(&hash_table, 10);
	//printf("%d", hash_table.capacity);

	for (int count_pages = 0; count_pages < number_pages; count_pages++)
	{
		read_number(&page);

		hits += LRU_step(&cache, &hash_table, page, count_pages, len_cache);

	}

	printf("%d\n", hits);

	return 0;

}

int read_number(int *number)
{
	int scan;

	scan = scanf("%d", number);

	assert(scan && "Input Error");

	if ((*number) < 0)
	{
		scan = 0;
		assert(scan && "Wrong format");
	}

	return 0;
}


