#include "main.h"


/**
 * set_bit - sets a value of a bit to 1 in index.
 *
 * @n: pointer of a number to change.
 *
 * @index: index of the bit.
 *
 * Return: 1 for true, -1 for false.
 */


int set_bit(unsigned long int *n, unsigned int index)
{
	size_t a;

	if (index > 63)
		return (-1);

	a = 1 << index;
	*n = (*n | a);

	return (1);
}

