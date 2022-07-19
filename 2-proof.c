#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

listint_t *change_no(listint_t **tmp);

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *a = NULL;
	int flag = 0;
	if (!*list)
		return;

	tmp = *list;

	while (tmp->next && *list)
	{
		flag = 1;

		if (tmp->n > tmp->next->n)
		{
			tmp = change_no(&tmp);
				if (!tmp->prev)
					*list = tmp;
			print_list(*list);
			a = tmp;
		}
	
		while (a->prev && a && flag)
		{
			if (a->prev->n > a->n)
			{
				a = a->prev;
				a = change_no(&tmp);
				if (!a->prev)
					*list = a;
				print_list(*list);
			}
			/*else
				flag = 0;*/
		} tmp = tmp->next;
		a = NULL;
	}
}


listint_t *change_no(listint_t **tmp)
{
	listint_t *t = NULL, *h = NULL;

	t = (*tmp)->next;
	h = *tmp;

	if (t->next)
	{
		t->next->prev = h;
        }
	if (h->prev)
		h->prev->next = t;
	/*else
		tmp->prev = NULL;*/

	h->next = t->next;;
	t->prev = h->prev;
	h->prev = t;
	t->next = h;

	return (t);
}
