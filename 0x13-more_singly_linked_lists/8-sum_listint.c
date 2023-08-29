#include "lists.h"

/**
 * sum_listint - finds the sum of the data in the list
 *
 * @head: pointer to the list
 *
 * Return: the sum
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	listint_t *let = head;

	while (let)
	{
		sum += let->n;
		let = let->next;
	}

	return (sum);
}

