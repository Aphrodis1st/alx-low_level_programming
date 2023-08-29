#include "lists.h"

/**
 * listint_len - lists numer of elements in a linked lists
 * @h: pointer to the list
 *
 * Return: number of nodes
 */


size_t listint_len(const listint_t *h)
{
	unsigned int count = 0;

	if (h == NULL)
		return (0);

	for (count = 0; h != NULL; count++)
	{
		h = h->next;

	}
	return (count);
}
