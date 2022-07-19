#include "sort.h"
#include <stdio.h>

void swap(int *pos1, int *pos2);

void insertion_sort_list(int s[], int size)
{
	int i, j;

	for (i = 1; i < size; i++)
	{
		j = i;
		while ((j > 0) && (s[j] < s[j - 1]))
		{
			printf("pasa\n");
			swap(&s[j], &s[j - 1]);
			j -= 1;
		}
	}
}

void swap(int *pos1, int *pos2)
{
	int *tmp;

	tmp = pos1;
	pos1 = pos2;
	pos2 = tmp;
}
