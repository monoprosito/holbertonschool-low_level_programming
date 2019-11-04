#include <stdlib.h>
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
	int flag = -1;
	listint_t *temp, *prev;

	if (head)
	{
		while (*head)
		{
			if (count == index)
			{
				temp = (*head)->next;
				free(*head);
				*head = temp;
				prev->next = temp;
				flag = 1;
			}

			prev = *head;	
			*head = (*head)->next;
			count++;
		}
	}

	return (flag);
}
