#include "sort.h"

int *do_swap(int *array, int current, int tmp);

/**
 * selection_sort - sorting algorithm
 * @array: array list
 * @size: size of the array
 *
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
	unsigned int j, c = 0;
	int current, flag, tmp;

	if (size < 2)
		return;

	while (c < size)
	{
		current = c, flag = 0, tmp = c;

		for (j = c + 1; j < size; j++)
		{
			if (array[j] < array[current])
				current = j, flag = 1;
		} c++;
		if (flag)
		{
			do_swap(array, current, tmp);
			print_array(array, size);
		}
	}
}

/**
 * do_swap - change positions value
 * @array: array list
 * @current: current pivot
 * @tmp: temporal pivot
 *
 * Return: None
 */
int *do_swap(int *array, int current, int tmp)
{
	int key;

	key  = array[current];
	array[current] = array[tmp];
	array[tmp] = key;

	return (array);
}
