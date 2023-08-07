#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* create_array - function creates array
* @size: size of the array
* @c: character
* Return: returns the array
*/
char *create_array(unsigned int size, char c)
{
	char *ptr;
	unsigned int i;

	if (size == 0)
		return (0);
	ptr = malloc(size * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ptr[i] = c;
	return (ptr);
}
