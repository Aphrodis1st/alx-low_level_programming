#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of listint_t
 *
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;

	listint_t *tmp;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	tmp = *head;

	if (*head == NULL)
	{
		*head = new;
	}

	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		tmp->next = new;
	}

	return (new);
}
