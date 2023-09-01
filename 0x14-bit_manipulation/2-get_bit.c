#include "main.h"

/**
 * get_bit - get bit at index
 * @n: The number
 * @index: The index
 * Return: The value of the bit, or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int maximum;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	maximum = 0x01;
	maximum <<= index;

	if ((n & maximum))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
