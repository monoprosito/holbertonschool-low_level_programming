#include <stdlib.h>
#include "lists.h"

/**
  * delete_dnodeint_at_index - ...
  * @head: ...
  * @index: ...
  *
  * Return: ...
  */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = NULL, *temp = NULL;
	unsigned int iter_times = 0;

	if (head == NULL)
		return (-1);

	if (*head)
	{
		current = *head;
		if (index == 0)
		{
			temp = current;
			if (current->next)
			{
				current = current->next;
				current->prev = temp->prev;
				*head = current;
			}
			else
				*head = NULL;

			free(temp);
			return (1);
		}

		while (current != NULL)
		{
			if (iter_times == index)
			{
				temp = current;
				current->prev->next = current->next;
				current->next->prev = current->prev;
				free(temp);
				return (1);
			}
			current = current->next;
			++iter_times;
		}
	}
	return (-1);
}
