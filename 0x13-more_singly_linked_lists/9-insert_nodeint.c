#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * insert_nodeint_at_index - ...
  * @head: ...
  * @idx: ...
  * @n: ...
  *
  * Return: ...
  */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp, *prev;
	unsigned int count = 0;

	if (head)
	{
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL)
			return (NULL);

		new_node->n = n;
		temp = *head;
		while (temp)
		{
			if (count == idx)
			{
				if (idx > 0)
				{
					new_node->next = temp;
					prev->next = new_node;
				}
				else
				{
					new_node->next = *head;
					*head = new_node;
				}

				return (new_node);
			}

			prev = temp;
			temp = temp->next;
			count++;
		}
	}

	return (NULL);
}
