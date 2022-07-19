#include "sort.h"

listint_t *change_no(listint_t **tmp);

/**
 * insertion_sort_list - sorta dlinked list
 * @list: dlinked list
 *
 * Return: none
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *t2 = NULL;

	if (!*list)
		return;

	tmp = *list;

	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			tmp = change_no(&tmp);
			print_list(*list);
			t2 = tmp;
		}

		if (t2 && t2->prev)
		{
			while (t2 && t2->prev)
			{
				if (t2->prev && t2->prev->n > t2->n)
				{
					t2 = t2->prev;
					t2 = change_no(&t2);
					if (t2->prev == NULL)
						*list = tmp;
					print_list(*list);
				}
				t2 = t2->prev;
			}
		}
		tmp = tmp->next;
	}
}

/**
 * change_no - change nodes postion
 * @tmp: temporal node
 *
 * Return: changed node position
 */
listint_t *change_no(listint_t **tmp)
{
	listint_t *t = NULL, *t_n = NULL;

	t = *tmp;
	t_n = (*tmp)->next;

	if (t_n->next)
		t_n->next->prev = t;
	if (t->prev)
		t->prev->next = t_n;
	t_n->prev = t->prev;
	t->next = t_n->next;
	t->prev = t_n;
	t_n->next = t;

	return (t);
}
