#include "main.h"
/**
 * *_strcat - concatenates @src to @dest
 * @src: the source string to append to @dest
 * @dest: the destiation string to be concatenated upon
 * Return:pointer to the resulting string
 */


char *_strcat(char *dest, char *src)
{
	int i, j;

	j = 0;
	while (dest[i] != '\0')
		i++;


	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
return (dest);
}
