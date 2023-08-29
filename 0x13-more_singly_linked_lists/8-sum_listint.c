#include "lists.h"

/**
 * sum_listint - finds the sum of the data in the list
 *
 * @head: pointer to the list
 *
 * Return: thee sum
 */

int sum_listint(listint_t *head)
{
	int sum;

	if (head == NULL)
		return (0);

	while (head != NULL)
	{
		sum += head->n;

		head = head->next;
	}

	return (sum);
}

