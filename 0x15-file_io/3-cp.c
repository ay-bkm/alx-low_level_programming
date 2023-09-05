#include "main.h"

#define BUFFER_SIZE 1024

/**
 * check_arguments - Check if the number of arguments is correct
 * @argc: Number of arguments
 */
void check_arguments(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * open_files - Open the files
 * @file_from: Pointer to the file descriptor of file_from
 * @file_to: Pointer to the file descriptor of file_to
 * @argv: Array of arguments
 */
void open_files(int *file_from, int *file_to, char *argv[])
{
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	*file_from = open(argv[1], O_RDONLY);
	if (*file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	*file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (*file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(*file_from);
		exit(99);
	}
}

/**
 * copy_content - Copy the content from file_from to file_to
 * @file_from: File descriptor of file_from
 * @file_to: File descriptor of file_to
 * @argv: Array of arguments
 */
void copy_content(int file_from, int file_to, char *argv[])
{
	int read_bytes, write_bytes;
	char buffer[BUFFER_SIZE];

	while ((read_bytes = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_bytes = write(file_to, buffer, read_bytes);
		if (write_bytes != read_bytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(file_from);
			close(file_to);
			exit(99);
		}
	}

	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(file_from);
		close(file_to);
		exit(98);
	}
}

/**
 * close_files - Close the files
 * @file_from: File descriptor of file_from
 * @file_to: File descriptor of file_to
 */
void close_files(int file_from, int file_to)
{
	if (close(file_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		close(file_to);
		exit(100);
	}

	if (close(file_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, exit with code on failure
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	check_arguments(argc);

	open_files(&file_from, &file_to, argv);

	copy_content(file_from, file_to, argv);

	close_files(file_from, file_to);

	return (0);
}
