#include "lists.h"

/**
 * looped_listint_len - Counts the number of unique nodes in the list
 *
 * @head: A pointer to the head of the list.
 *
 * Return: If the list is not looped - 0.
 *
 * Otherwise - the number of unique nodes in the list.
 */

size_t looped_listint_len(const listint_t *head)

{
	const listint_t *tech, *issue;
	unsigned int nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tech = head->next;
	issue = (head->next)->next;

	while (issue)
	{
		if (tech == issue)
		{
			tech = head;
		while (tech != issue)
		{
			nodes++;
			tech = tech->next;
			issue = issue->next;
		}

		tech = tech->next;
		while (tech != issue)
		{
			nodes++;
			tech = tech->next;
		}

		return (nodes);
		}

		tech = tech->next;
		issue = (issue->next)->next;
	}

	return (0);
}


/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */


size_t print_listint_safe(const listint_t *head)

{
	unsigned int nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}

