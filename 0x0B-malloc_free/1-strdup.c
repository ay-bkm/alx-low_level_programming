#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _strdup - Duplicates a string
 * @str: the string
 * Return: dstr, duplicate string
 */
char *_strdup(char *str)
{
	int i, s_size = 1;
	char *dstr;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		s_size++;

	dstr = (char *)malloc(s_size * sizeof(char));
	if (dstr == NULL)
		return (NULL);
	for (i = 0; i < s_size; i++)
		dstr[i] = str[i];
	return (dstr);
}
