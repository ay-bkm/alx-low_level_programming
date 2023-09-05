#include "main.h"

/**
 * check_arguments - Check if the number of arguments is correct
 * @argc: Number of arguments
 */
void check_arguments(int argc)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
}

/**
 * open_file - Open the file
 * @file: Pointer to the file descriptor
 * @argv: Array of arguments
 */
void open_file(int *file, char *argv[])
{
	*file = open(argv[1], O_RDONLY);
	if (*file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
		exit(98);
	}
}

/**
 * read_elf_header - Read the ELF header
 * @file: File descriptor
 * @ehdr: Pointer to the ELF header structure
 */
void read_elf_header(int file, Elf64_Ehdr *ehdr)
{
	ssize_t bytes_read;

	bytes_read = read(file, ehdr, sizeof(*ehdr));
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read ELF header\n");
		close(file);
		exit(98);
	}
	if (bytes_read != sizeof(*ehdr))
	{
		dprintf(STDERR_FILENO, "Error: ELF header is truncated\n");
		close(file);
		exit(98);
	}
}

/**
 * check_elf_header - Check if the file is an ELF file
 * @ehdr: Pointer to the ELF header structure
 */
void check_elf_header(Elf64_Ehdr *ehdr)
{
	if (ehdr->e_ident[EI_MAG0] != ELFMAG0 ||
		ehdr->e_ident[EI_MAG1] != ELFMAG1 ||
		ehdr->e_ident[EI_MAG2] != ELFMAG2 ||
		ehdr->e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_magic - Print the magic numbers
 * @ehdr: Pointer to the ELF header structure
 */
void print_magic(Elf64_Ehdr *ehdr)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ehdr->e_ident[i]);
	printf("\n");
}

/**
 * get_class - Get the class of the ELF file
 * @ehdr: Pointer to the ELF header structure
 *
 * Return: String representing the class of the ELF file
 */
char *get_class(Elf64_Ehdr *ehdr)
{
	char *class;

	switch (ehdr->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			class = "none";
			break;
		case ELFCLASS32:
			class = "ELF32";
			break;
		case ELFCLASS64:
			class = "ELF64";
			break;
		default:
			class = "<unknown: %x>";
			break;
	}

	return (class);
}

/**
 * print_class - Print the class of the ELF file
 * @ehdr: Pointer to the ELF header structure
 */
void print_class(Elf64_Ehdr *ehdr)
{
	printf("  Class:                         %s\n", get_class(ehdr));
}

/**
 * get_data - Get the data encoding of the ELF file
 * @ehdr: Pointer to the ELF header structure
 *
 * Return: String representing the data encoding of the ELF file
 */
char *get_data(Elf64_Ehdr *ehdr)
{
	char *data;

	switch (ehdr->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			data = "none";
			break;
		case ELFDATA2LSB:
			data = "2's complement, little endian";
			break;
		case ELFDATA2MSB:
			data = "2's complement, big endian";
			break;
		default:
			data = "<unknown: %x>";
			break;
	}

	return (data);
}

/**
 * print_data - Print the data encoding of the ELF file
 * @ehdr: Pointer to the ELF header structure
 */
void print_data(Elf64_Ehdr *ehdr)
{
	printf("  Data:                           %s\n", get_data(ehdr));
}

/**
 * get_version - Get the version of the ELF file
 * @ehdr: Pointer to the ELF header structure
 *
 * Return: String representing the version of the ELF file
 */
char *get_version(Elf64_Ehdr *ehdr)
{
	char *version;

	switch (ehdr->e_ident[EI_VERSION])
	{
		case EV_NONE:
			version = "0 (invalid)";
			break;
		case EV_CURRENT:
			version = "1 (current)";
			break;
		default:
			version = "<unknown: %lx>";
			break;
	}

	return (version);
}

/**
 * print_version - Print the version of the ELF file
 * @ehdr: Pointer to the ELF header structure
 */
void print_version(Elf64_Ehdr *ehdr)
{
	printf("  Version:                           %s\n", get_version(ehdr));
}

/**
 * get_osabi - Get the OS/ABI of the ELF file
 * @ehdr: Pointer to the ELF header structure
 *
 * Return: String representing the OS/ABI of the ELF file
 */
char *get_osabi(Elf64_Ehdr *ehdr)
{
	char *osabi;

	switch (ehdr->e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			osabi = "UNIX - System V";
			break;
		case ELFOSABI_HPUX:
			osabi = "UNIX - HP-UX";
			break;
		case ELFOSABI_NETBSD:
			osabi = "UNIX - NetBSD";
			break;
		case ELFOSABI_LINUX:
			osabi = "UNIX - Linux";
			break;
		case ELFOSABI_SOLARIS:
			osabi = "UNIX - Solaris";
			break;
		case ELFOSABI_IRIX:
			osabi = "UNIX - IRIX";
			break;
		case ELFOSABI_FREEBSD:
			osabi = "UNIX - FreeBSD";
			break;
		case ELFOSABI_TRU64:
			osabi = "UNIX - TRU64";
			break;
		case ELFOSABI_ARM:
			osabi = "ARM";
			break;
		case ELFOSABI_STANDALONE:
			osabi = "Standalone App";
			break;
		default:
			osabi = "<unknown: %x>";
			break;
	}

	return (osabi);
}

/**
 * print_osabi - Print the OS/ABI of the ELF file
 * @ehdr: Pointer to the ELF header structure
 */
void print_osabi(Elf64_Ehdr *ehdr)
{
	printf("  OS/ABI:                            %s\n", get_osabi(ehdr));
}

/**
 * print_abiversion - Print the ABI version of the ELF file
 * @ehdr: Pointer to the ELF header structure
 */
void print_abiversion(Elf64_Ehdr *ehdr)
{
	printf("  ABI Version:                   %d\n", ehdr->e_ident[EI_ABIVERSION]);
}

/**
 * get_type - Get the type of the ELF file
 * @ehdr: Pointer to the ELF header structure
 *
 * Return: String representing the type of the ELF file
 */
char *get_type(Elf64_Ehdr *ehdr)
{
	char *type;

	switch (ehdr->e_type)
	{
		case ET_NONE:
			type = "NONE (None)";
			break;
		case ET_REL:
			type = "REL (Relocatable file)";
			break;
		case ET_EXEC:
			type = "EXEC (Executable file)";
			break;
		case ET_DYN:
			type = "DYN (Shared object file)";
			break;
		case ET_CORE:
			type = "CORE (Core file)";
			break;
		default:
			type = "<unknown>: %x";
			break;
	}

	return (type);
}

/**
 * print_type - Print the type of the ELF file
 * @ehdr: Pointer to the ELF header structure
 */
void print_type(Elf64_Ehdr *ehdr)
{
	printf("  Type:                              %s\n", get_type(ehdr));
}

/**
 * print_entry - Print the entry point address of the ELF file
 * @ehdr: Pointer to the ELF header structure
 */
void print_entry(Elf64_Ehdr *ehdr)
{
	printf("  Entry point address:               %#lx\n", ehdr->e_entry);
}

/**
 * close_file - Close the file
 * @file: File descriptor
 */
void close_file(int file)
{
	if (close(file) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot close file\n");
		exit(98);
	}
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, exit with code on failure
 */
int main(int argc, char **argv)
{
	int file;
	Elf64_Ehdr ehdr;

	check_arguments(argc);

	open_file(&file, argv);

	read_elf_header(file, &ehdr);

	check_elf_header(&ehdr);
	print_magic(&ehdr);
	print_class(&ehdr);
	print_data(&ehdr);
	print_version(&ehdr);
	print_osabi(&ehdr);
	print_abiversion(&ehdr);
	print_type(&ehdr);
	print_entry(&ehdr);

	close_file(file);

	return (0);
}
