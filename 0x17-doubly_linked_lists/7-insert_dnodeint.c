#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * insert_dnodeint_at_index - Inserts a new node at a given position
  * @h: The head of the doubly linked list
  * @idx: The index in which insert the new node
  * @n: The number to insert in the new node
  *
  * Return: The address of the new node, or NULL if it failed
  */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current = NULL, *prev = NULL, *new_node = NULL;
	unsigned int iter_times = 0;

	if (h)
	{
		current = *h;
		if (current)
		{
			while (current != NULL)
			{
				if (iter_times == idx)
				{
					new_node = create_node(n, current, current->prev);
					current->prev = new_node;
					current = new_node;
					if (idx == 0)
						*h = new_node;
					else
						current->prev->next = new_node;
					return (new_node);
				}
				++iter_times;

				prev = current;
				current = current->next;
			}

			if (iter_times == idx - 1)
			{
				new_node = create_node(n, prev->next, prev);
				prev->next = new_node;
				return (new_node);
			}
		}
		new_node = create_node(n, *h, NULL);
		*h = new_node;
		return (new_node);
	}

	return (NULL);
}

/**
  * create_node - Create a new node with values
  * @n: The number of the new node
  * @next: The next node of the new node
  * @prev: The previous node of the new node
  *
  * Return: The address of the new node created
  */
dlistint_t *create_node(unsigned int n, void *next, void *prev)
{
	dlistint_t *new_node = NULL;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = next;
	new_node->prev = prev;
	return (new_node);
}
