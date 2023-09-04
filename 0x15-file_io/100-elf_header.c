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


/**
 * print_magic - function that outputs magic numbers of an ELF header.
 *
 * @e_ident: An array pointer containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 *
 */


void print_magic(unsigned char *e_ident)

{
	int idx;

	printf(" Magic: ");

	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", e_ident[idx]);

		if (idx == EI_NIDENT - 1)
			printf("\n");

		else
			printf(" ");
	}
}


/**
 *
 * print_class - a function that outputs the class of an ELF header.
 * @e_ident: An array pointer that containing the ELF class.
 *
 */


void print_class(unsigned char *e_ident)

{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;

	case ELFCLASS32:
		printf("ELF32\n");
		break;

	case ELFCLASS64:
		printf("ELF64\n");
		break;

	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 *
 * print_data - a function that outputs the data of an ELF header.
 * @e_ident: An array pointer that containing the ELF class.
 *
 */


void print_data(unsigned char *e_ident)

{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;

	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;

	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;

	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 * print_version - a function to output the  version of an ELF header.
 * @e_ident: An array pointer that containing the ELF version.
 *
 */


void print_version(unsigned char *e_ident)

{
	 printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;

	default:
		printf("\n");
		break;
	}
}


/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: An array pointer that contans the ELF version.
 *
 */

void print_osabi(unsigned char *e_ident)

{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;

	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;

	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;

	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;

	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;

	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;

	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;

	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;

	case ELFOSABI_ARM:
		printf("ARM\n");
		break;

	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - a function that outputs ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 *
 */

void print_abi(unsigned char *e_ident)

{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * print_type - a function that outputs type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 *
 */


void print_type(unsigned int e_type, unsigned char *e_ident)

{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;

	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;

	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;

	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;

	case ET_CORE:
		printf("CORE (Core file)\n");
		break;

	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - a function to output the entry point of an ELF header.
 * @i_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 *
 */

void print_entry(unsigned long int i_entry, unsigned char *e_ident)

{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		i_entry = ((i_entry << 8) & 0xFF00FF00) |
			  ((i_entry >> 8) & 0xFF00FF);
		i_entry = (i_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", i_entry);
}


/**
 * close_elf - a function that closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */


void close_elf(int elf)

{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the ELF header
 *
 * @argc: The number of arguments supplied to the program.
 *
 * @argv: An array pointers to the arguments.
 *
 * Return: 0 if is true.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */


int main(int __attribute__((__unused__)) argc, char *argv[])

{
	Elf64_Ehdr *header;
	int op, re;

	op = open(argv[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(op);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	re = read(op, header, sizeof(Elf64_Ehdr));
	if (re == -1)
	{
		free(header);
		close_elf(op);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}


	free(header);
	close_elf(op);
	return (0);
}

