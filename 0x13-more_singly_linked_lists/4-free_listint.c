#include "lists.h"

/**
 * free_listint - a function to free a linked list
 *
 * @head: listint_t list to be freed
 *
 */

void free_listint(listint_t *head)
{
	listint_t *fr;

	while ((fr = head) != NULL)
	{
		head = head->next;
		free(fr);
	}
}

