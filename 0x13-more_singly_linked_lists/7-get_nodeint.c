#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a given index in a list
 *
 * @head: first node in the linked list
 * @index: index desired position to return
 *
 * Return: pointer to the node we're looking for, or NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int n;

	for (n = 0; n < index; n++)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
	}

	return (head);
}


