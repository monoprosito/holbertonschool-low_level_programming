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
	listint_t *new_node, *iter, *prev;
	unsigned int count = 0;

	if (head)
	{
		new_node = malloc(sizeof(listint_t));
		if (new_node == NULL)
			return (NULL);

		new_node->n = n;
		if (idx == 0)
		{
			new_node->next = *head;
			*head = new_node;
		}
		else
		{
			iter = *head;
			while (iter)
			{
				if (count == idx)
				{
					new_node->next = iter;
					prev->next = new_node;
				}
				prev = iter;
				iter = iter->next;
				count++;
			}
			if (iter == NULL)
			{
				new_node->next = NULL;
				prev->next = new_node;
				return (new_node);
			}
		}
		return (new_node);
	}
	return (NULL);
}
