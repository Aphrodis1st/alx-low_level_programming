#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */


list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newNode, *temp;
	size_t i, count = 0;

	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
		return (NULL);

	newNode->str = strdup(str);
	for (i = 0; str[i] != '\0'; i++)
		count++;

	newNode->len = count;
	newNode->next = NULL;

	temp = *head;

	if (temp == NULL)
		*head = newNode;

	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}

	return (*head);
}
