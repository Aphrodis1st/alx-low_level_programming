#include "lists.h"

/**
 * print_listint - prints all the int data of a linked list
 * @h: pointer of head list
 *
 * Return: number of nodes in the list
 */


size_t print_listint(const listint_t *h)

{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);

	num++;
	h = h->next;
	}

	return (count);
}

