#include "main.h"


/**
 * print_binary - prints the binary representation equiv
 *
 * @n: function to print binary
 *
 * Return: none
 */


void print_binary(unsigned long int n)

{
	int a;
	int bin = 0;

	size_t old;

	for (a = 63; a >= 0; a--)
	{
		old = n >> a;

		if (old & 1)
		{
			_putchar('1');
			bin++;
		}
		else if (bin)
			_putchar('0');
	}
	if (!bin)
		_putchar('0');
}

