#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 in the index.
 *
 * @n: pointer of an index.
 *
 * @index: index of the bit.
 *
 * Return: 1 for true and -1 for false.
 */


int clear_bit(unsigned long int *n, unsigned int index)

{
	size_t a;

	if (index > 63)
		return (-1);

	a = 1 << index;

	if (*n & a)
		*n ^= a;

	return (1);
}
