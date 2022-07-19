#include "sort.h"

void shell_sorting_function(int *array, int size, int gap);

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm and the Knuth sequence
 *
 * @array: array of integers
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	if (array == NULL || size < 2)
		return;

	while (gap < size)
		gap = (gap * 3) + 1;

	while ((gap = (gap + 1) / 3) > 0)
		sorting_algorithm(array, size, gap);
}

/**
 * shell_sorting_function - sorts an array of integers in ascending order
 * using the Shell sort algorithm and the Knuth sequence
 *
 * @array: array of integers
 * @size: size of the array
 * @gap: gap between elements
 *
 * Return: void
 */
void shell_sorting_function(int *array, int size, int gap)
{
	int i, j, temp;

	for (i = gap; i < size; i++)
	{
		temp = array[i];

		for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			array[j] = array[j - gap];
		array[j] = temp;
	}

	print_array(array, size);
}
