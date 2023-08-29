#include "lists.h"

/**
 * print_listint - prints all the int data of a linked list
 * @h: pointer of head list
 *
 * Return: number of nodes in the list
 */


size_t print_listint(const listint_t *h)
{
	unsigned int count = 0;

	if (h == NULL)
		return (0);

	for (count = 0; h != NULL; count++)
	{
		printf("%d\n", h->n);

		h = h->next;
	}
	return (count);
}
