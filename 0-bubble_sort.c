#include "sort.h"

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



/**
 * bubble_sort - order an array in ascenden form
 * @array: array
 * @size: size of the array
 *
 * Return: none
 */
void bubble_sort(int *array, size_t size)
{
	size_t j;
	unsigned long int c = 0;
	int flag = 1;

	if (size < 2)
		return;

	while (size > 0 && flag)
	{
		flag = 0;
		for (j = 1; j < (size - c); j++)
		{
			if (array[j - 1] > array[j])
			{
				flag++;
				do_swap(array, (j - 1), j);
				print_array(array, size);
			}
		} c++;
	}
}
