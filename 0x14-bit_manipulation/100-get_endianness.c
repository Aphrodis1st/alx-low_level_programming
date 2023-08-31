#include "main.h"

/**
 * get_endianness - checks if there is an indianess and
 *
 * Return: 0 if is big and 1 for little
 */


int get_endianness(void)
{
	size_t a = 1;
	char *x = (char *) &a;

	return (*x);
}

