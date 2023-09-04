#include "main.h"

/**
 * create_file - Creates or overwrites a file.
 * @filename: The name of the file.
 * @text_content: The text to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status, content_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (content_length = 0; text_content[content_length];)
			content_length++;
	}

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	write_status = write(file_descriptor, text_content, content_length);

	if (file_descriptor == -1 || write_status == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}
