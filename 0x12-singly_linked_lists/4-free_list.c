#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed from list_t
 */


void free_list(list_t *head)
{
	list_t *pln;

	while (head)
	{
		pln = head->next;
		free(head->str);
		free(head);

		head = pln;
	}
}

