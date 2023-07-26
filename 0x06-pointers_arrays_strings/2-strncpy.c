#include "main.h"
/**
 * _strncpy - copies string from src to dest
 * @src: string
 * @dest: destination
 * @n: number of bytes
 * Return: dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] && i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
