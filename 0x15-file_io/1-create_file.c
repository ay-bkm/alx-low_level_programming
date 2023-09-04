#include "main.h"
/**
 * create_file - create file
 * @filename: pointer to the file
 * @text_content: pointer to string
 * Return: -1 or 1
 */
int create_file(const char *filename, char *text_content)
{
	int file_desc;
	ssize_t length;

	if (!filename)
		return (-1);

	file_desc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (file_desc == -1)
		return (-1);

	if (text_content)
	{
		length = write(file_desc, text_content, strlen(text_content));
		if (length == -1)
			return (-1);
	}

	close(file_desc);
	return (1);
}
