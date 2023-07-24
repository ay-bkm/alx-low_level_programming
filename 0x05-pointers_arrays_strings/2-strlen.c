#include "main.h"

/**
 * _strlen - length of string
 * @s: character pointer
 * Return: length of string
 */
int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
	{
		++c;
	}

	return (c);
}
