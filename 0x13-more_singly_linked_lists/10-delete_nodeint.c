#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * delete_nodeint_at_index - ...
  * @head: ...
  * @index: ...
  *
  * Return: ...
  */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *prev, *iter, *next;

	if (head)
	{
		iter = *head;
		prev = iter;
		while (iter->next)
		{
			if (count == index)
			{
				if (index == 0)
				{
					next = iter->next->next;
					free(iter);
					iter = prev->next;
					iter->next = next;
					*head = iter;
				}
				else
				{
					next = iter->next;
					free(iter);
					iter = prev;
					iter->next = next;
				}
				return (1);
			}

			prev = iter;
			iter = iter->next;
			count++;
		}
	}
	
	return (-1);
}
