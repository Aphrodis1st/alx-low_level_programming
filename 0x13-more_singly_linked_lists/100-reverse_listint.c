#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */

listint_t *reverse_listint(listint_t **head)

{
	listint_t *current_tmp;
	listint_t *new_tmp;

	if (head == NULL || *head == NULL)
		return (NULL);

	current_tmp = *head;
	*head = current_tmp->next;

	current_tmp->next = NULL;

	while (*head != NULL)
	{
		new_tmp = (*head)->next;
		(*head)->next = current_tmp;

		current_tmp = *head;
		if (new_tmp == NULL)
			return (*head);
		*head = new_tmp;
	}

	if (*head == NULL)
	{
		*head = current_tmp;
			return (*head);
	}

	return (NULL);
}

