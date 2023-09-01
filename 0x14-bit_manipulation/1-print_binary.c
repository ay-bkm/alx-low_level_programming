#include "main.h"
/**
 * print_binary - prints binary
 * @n: the number
 * Return: void 
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int i, flag = 0;

	for (i = 63; i >= 0; i--)
	{
		if ((n >> i) & mask)
		{
			flag = 1;
			_putchar('1');
		}
		else if (flag)
			_putchar('0');
	}
	if (!flag)
		_putchar('0');
}
