#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * insert_dnodeint_at_index - Inserts a new node at a given position
  * @h: The head of the doubly linked list
  * @idx: The index in which insert the new node
  *
  * Return: The address of the new node, or NULL if it failed
  */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current = *h, *new_node = NULL;
	unsigned int iter_times = 0;
	
	if (current)
	{
		new_node = malloc(sizeof(dlistint_t));
		if (new_node == NULL)
			return (NULL);

		new_node->n = n;
		while (current != NULL)
		{
			if (iter_times == idx)
			{
				new_node->next = current;
				new_node->prev = current->prev;
				current->prev = new_node;
				return (new_node);
			}

			current = current->next;
			++iter_times;
		}
	}

	return (NULL);
}
