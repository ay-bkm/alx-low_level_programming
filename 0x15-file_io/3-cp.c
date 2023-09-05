#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * allocate_buffer - Allocates a 1024-byte buffer for file copying.
 * @dest_file: The name of the destination file for copying.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *dest_file)
{
	char *copy_buffer;

	copy_buffer = malloc(sizeof(char) * 1024);

	if (copy_buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Unable to allocate buffer for %s\n", dest_file);
		exit(99);
	}

	return (copy_buffer);
}

/**
 * close_descriptor - Closes a file descriptor.
 * @desc: The file descriptor to be closed.
 */
void close_descriptor(int desc)
{
	int result;

	result = close(desc);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d\n", desc);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another file.
 * @argc: The number of command-line arguments provided.
 * @argv: An array of pointers to the command-line arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with specific error codes if:
 * - The argument count is incorrect (exit code 97).
 * - The source file does not exist or cannot be read (exit code 98).
 * - The destination file cannot be created or written to (exit code 99).
 * - Either the source or destination file cannot be closed (exit code 100).
 */
int main(int argc, char *argv[])
{
	int src_file, dest_file, read_bytes, write_bytes;
	char *copy_buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: copy_program source_file destination_file\n");
		exit(97);
	}

	copy_buffer = allocate_buffer(argv[2]);
	src_file = open(argv[1], O_RDONLY);
	read_bytes = read(src_file, copy_buffer, 1024);
	dest_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (src_file == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Unable to read from source file %s\n", argv[1]);
			free(copy_buffer);
			exit(98);
		}

		write_bytes = write(dest_file, copy_buffer, read_bytes);
		if (dest_file == -1 || write_bytes == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Unable to write to destination file %s\n", argv[2]);
			free(copy_buffer);
			exit(99);
		}

		read_bytes = read(src_file, copy_buffer, 1024);
		dest_file = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);

	free(copy_buffer);
	close_descriptor(src_file);
	close_descriptor(dest_file);

	return (0);
}
