#include "main.h"

/**
 * flip_bits - function that counts number of bits
 * to change.
 * @n: first number
 *
 * @m: second number
 *
 * Return: number of bits to change
 */


unsigned int flip_bits(unsigned long int n, unsigned long int m)

{

	int bits = 0;
	int a;

	unsigned int long include;
	unsigned int long execlude = n ^ m;

	for (a = 63; a >= 0; a--)
	{
		include = execlude >> a;
		if (include & 1)
			bits++;
	}

	return (bits);
}
