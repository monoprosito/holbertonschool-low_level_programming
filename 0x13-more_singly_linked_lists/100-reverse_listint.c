#include <stdlib.h>
#include "lists.h"

/**
  * reverse_listint - ...
  * @head: ...
  *
  * Return: ...
  */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next;

	if ((*head)->next)
	{
		while (*head)
		{
			next = *head;
			*head = (*head)->next;
			next->next = prev;
			prev = next;
		}

		*head = prev;
	}

	return (*head);
}
