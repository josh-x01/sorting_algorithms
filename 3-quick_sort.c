#include "sort.h"

int *do_swap(int *array, int pos1, int pos2);
ssize_t partition(int *array, ssize_t low, ssize_t high, size_t size);
void keep_sort(int *array, ssize_t low, ssize_t high, size_t size);

/**
 * quick_sort -sorting algoritmh
 * @array: list array
 * @size: size array
 *
 * Return: none
 */
void quick_sort(int *array, size_t size)
{
	unsigned int low, high;

	if (size < 2 || !array)
		return;

	low = 0, high = size - 1;

	keep_sort(array, low, high, size);
}

/**
 * keep_sort - keep sorting the array
 * @array: list array
 * @low: low pont of the array
 * @high: high part of the array
 * @size: size array
 *
 * Return: none
 */
void keep_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		keep_sort(array, low, pivot - 1, size);
		keep_sort(array, pivot + 1, high, size);
	}
}

/**
 * partition - partition the array
 * @array: list array
 * @low: low part of the array
 * @high: high part of the array
 * @size: size array
 *
 * Return: pivot point in the partitioned array
 */
ssize_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot;
	ssize_t i, j;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				do_swap(array, i, j);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] > array[high])
	{
		do_swap(array, (i + 1), high);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * do_swap - change  positions in array
 * @array: array list
 * @pos1: position to change
 * @pos2: position to change
 *
 * Return: array pointer
 */
int *do_swap(int *array, int pos1, int pos2)
{
	array[pos1] = array[pos1] ^ array[pos2];
	array[pos2] = array[pos1] ^ array[pos2];
	array[pos1] = array[pos1] ^ array[pos2];
	return (array);
}
