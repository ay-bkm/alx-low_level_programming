#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes
 * Return: concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j, k;
	char *s3;
	unsigned int x;

	s3 = NULL;
	i = 0;
	j = 0;
	k = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;

	if (n >= j)
		n = j;

	s3 = malloc((i + n + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);

	for (x = 0; x < i; x++)
		s3[k++] = s1[x];
	for (x = 0; x < n; x++)
		s3[k++] = s2[x];
	s3[k] = '\0';

}
