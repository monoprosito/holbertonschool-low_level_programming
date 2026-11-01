#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * add_nodeint_end - Adds a new node to the end of a linked list
  * @head: The head of the linked list
  * @n: The value to add to the end of the linked list
  *
  * Return: The address of the new element, or NULL it failed
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_list, *temp;

	if (head)
	{
		new_list = malloc(sizeof(listint_t));
		if (new_list == NULL)
			return (NULL);

		new_list->n = n;
		new_list->next = NULL;

		if (*head == NULL)
		{
			*head = new_list;
			return (*head);
		}
		else
		{
			temp = *head;
			while (temp->next)
				temp = temp->next;

			temp->next = new_list;
			return (temp);
		}
	}

	return (NULL);
}
