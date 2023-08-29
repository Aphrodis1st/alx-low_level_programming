#include "lists.h"


/**
 * add_nodeint - adds a new node at the beginning of the listint_t
 * @head: pointer to the first node in the list
 * @n: data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */


listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newNode;

	if (head == NULL)
		return (NULL);

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
		return (NULL);

	if (*head == NULL)
		newNode->next = NULL;

	else
		newNode->next = *head;

	newNode->n = n;
	*head = newNode;

	return (newNode);
}

