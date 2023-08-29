#include "lists.h"

/**
 * free_listint_safe - frees a elements from the list
 * @h: pointer to the list
 *
 * Return: number of elements in the freed list
 */

size_t free_listint_safe(listint_t **h)

{
	unsigned int len = 0;
	int fr;

	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		fr = *h - (*h)->next;
		if (fr > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			len++;
		}
		else
		{
			free(*h);
			*h = NULL;
			len++;
			break;
		}
	}

	*h = NULL;

	return (len);
}

