#include "lists.h"

/**
 * create_newNode - creates a new node in the list
 *
 * @n: data of the node
 *
 * Return: data to the pointer
 */

listint_t *create_newNode(int n)

{
	listint_t *newNode;

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	return (newNode);
}


/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */



listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)

{
	unsigned int a;
	listint_t *tmp;
	listint_t *tmp_current;
	listint_t *newNode;

	tmp = *head;

	if (head == NULL)
		return (NULL);

	newNode = create_newNode(n);

	if (newNode == NULL)
		return (NULL);

	if (*head == NULL)
	{
		*head = newNode;
		return (newNode);
	}

	if (idx == 0)
		*head = newNode;

	for (a = 0; a < idx - 1 && tmp != NULL && idx != 0; a++)
		tmp = tmp->next;

	if (tmp == NULL)
		return (NULL);

	if (idx == 0)
		newNode->next = tmp;
	else
	{
		tmp_current = tmp->next;
		tmp->next = newNode;
		newNode->next = tmp_current;
	}
	return (newNode);
}
