#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: result of concatenation
 */

char *str_concat(char *s1, char *s2)
{
	int i, j, s2_size = 0, s1_size = 0;
	char *result;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0; s2[i]; i++)
		s2_size++;
	for (i = 0; s1[i]; i++)
		s1_size++;

	result = (char *)malloc(s1_size + s2_size + 1);

	if (result == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		result[i] = s1[i];

	for (j = 0; s2[j]; j++)
		result[i + j] = s2[j];

	result[i + j] = '\0';
return (result);
}
