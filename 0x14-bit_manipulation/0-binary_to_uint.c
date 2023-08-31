#include "main.h"
/**
 * binary_to_uint - converts a binary number
 * @b: pointing to a string
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int i, len;
	unsigned int decnum, decval;

	if (b == NULL)
		return (0);

	len = strlen(b);
	for (i = 0; i < len; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}

	decval = 1;
	decnum = 0;
	for (i = len - 1; i >= 0; i--)
	{
		if (b[i] == '1')
			decnum += decval;
		decval *= 2;
	}

	return (decnum);
}
