#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - prints name
 * @name: name to print
 * @f: function pointer
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || name == NULL)
		return;
	f(name);
}
