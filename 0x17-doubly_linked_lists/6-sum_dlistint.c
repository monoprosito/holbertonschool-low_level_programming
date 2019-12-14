#include <stdlib.h>
#include "lists.h"

/**
  * sum_dlistint - Sum of all data (n) in a doubly linked list
  * @head: The head of the doubly linked list
  *
  * Return: The sum of all data
  */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	int sum = 0;

	if (head)
	{
		while (current != NULL)
		{
			sum += current->n;
			current = current->next;
		}
	}

	return (sum);
}
