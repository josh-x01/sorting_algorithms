#include "sort.h"
#include <stdio.h>

int *do_swap(int *array, int pos1, int pos2);

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				do_swap(array, j, j + 1);
				print_array(array, size);
			}
		}
	}
}


int *do_swap(int *array, int pos1, int pos2)
{
	int key;

	key  = array[pos1];
	array[pos1 ]= array[pos2];
	array[pos2] = key;
	return (array);

}
