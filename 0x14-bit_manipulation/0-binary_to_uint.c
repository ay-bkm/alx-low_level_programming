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

	decval = 1;
	decnum = 0;
	len = strlen(b) - 1;
	for (i = len; i >= 0; i--)
	{

		if (b[i] == '0')
		{
			decval *= 2;
		}
		else if (b[i] == '1')
		{
			decnum += decval;
			decval *= 2;
		}
		else if (b == NULL || b[i] != '0' || b[i] != '1')
		{
			return (0);
		}
	}
	return (decnum);
}
