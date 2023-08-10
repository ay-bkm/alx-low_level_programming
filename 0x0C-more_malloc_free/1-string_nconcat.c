#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings with a limit on the second string
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes from s2 to concatenate
 *
 * Return: Pointer to the concatenated string, or NULL if allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j, k;
	char *s3;
	unsigned int x;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = 0;
	j = 0;

	while (s1[i])
		i++;
	while (s2[j])
		j++;

	if (n >= j)
		n = j;

	s3 = malloc((i + n + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);

	for (k = 0; k < i; k++)
		s3[k] = s1[k];
	for (x = 0; x < n; x++)
		s3[k++] = s2[x];
	s3[k] = '\0';

	return (s3);
}
