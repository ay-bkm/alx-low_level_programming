#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip
 * @n: first number
 * @m: second number
 * Return: the number of bits needed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;
	unsigned int count = 0;

	while (diff)
	{
		count += diff & 1;
		diff >>= 1;
	}

	return (count);
}
