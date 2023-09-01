#include "main.h"

/**
 * get_bit - get bit at index
 * @n: The number
 * @index: The index
 * Return: The value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int maximum;

	maximum = 0x01;
	maximum <<= index;
	if (maximum == 0)
		return (-1);

	if ((n & maximum))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
