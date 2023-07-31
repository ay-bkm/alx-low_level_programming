#include "main.h"
/**
* _memset - fills memory with constant byte
* @s: memory area
* @b: constant char
* @n: number of bytes
* Return: the memory area of s
*/
char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		s[i] = b;
	}
return (s);
}
