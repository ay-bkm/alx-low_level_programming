#include "main.h"
/**
 * read_textfile - read and write
 * @filename: just a pointer to the file
 * @letters: number of letters
 * Return: number of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_desc;
	ssize_t written;
	ssize_t nb;

	file_desc = open(filename, O_RDONLY);
	if (file_desc == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	nb = read(file_desc, buffer, letters);
	written = write(1, buffer, nb);

	free(buffer);
	close(file_desc);
	return (written);
}
