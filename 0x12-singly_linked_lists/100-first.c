#include <stdio.h>

void fst(void) __attribute__ ((constructor));

/**
 * fst - prints a sentence before the main
 * function is executed
 */


void fst(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

