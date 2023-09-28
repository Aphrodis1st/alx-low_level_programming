#include "main.h"


/**
 * binary_to_uint - converts a binary to an unsigned int
 *
 * @b: a string to thebinary.
 *
 * Return: converted number or 0 if b is NULL.
 */


unsigned int binary_to_uint(const char *b)

{
	size_t a;

	int less;
	int base_two;

	if (!b)
		return (0);

	a = 0;

	for (less = 0; b[less] != '\0'; less++)
		;

	for (less--, base_two = 1; less >= 0; less--, base_two *= 2)
	{
		if (b[less] != '0' && b[less] != '1')
		{
			return (0);
		}

		if (b[less] & 1)
		{
			a += base_two;
		}
	}

	return (a);
}

