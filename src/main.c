#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Doubly_connected_list.h "


#define K 3
#define relative_hash_table_size 0.1


int read_number(int *number);


int main()
{
	int scan, len_cache, len_hash_table, number_pages, page, hits;
	struct List cache;
	struct Hash hash_table;
	hits = 0;

	read_number(&len_cache);

	read_number(&number_pages);

	//cache = create_cache(len_cache);

	len_hash_table = relative_hash_table_size * number_pages;
	//hash_table = create_hash_table(len_hash_table);


	for (int count_pages = 0; count_pages < number_pages; count_pages++)
	{
		read_number(&page);

		//cache = append_page(page, hash_table, cache, &hits);

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


