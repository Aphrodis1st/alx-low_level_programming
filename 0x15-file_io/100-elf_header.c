#include "main.h"


/**
 * check_elf - Checks ELF files.
 * @e_ident: A pointer array that containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 *
 */


void check_elf(unsigned char *e_ident)

{
	int idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (e_ident[idx] != 127 &&
		    e_ident[idx] != 'E' &&
		    e_ident[idx] != 'L' &&
		    e_ident[idx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}



