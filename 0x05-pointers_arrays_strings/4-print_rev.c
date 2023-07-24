#include "main.h"
#include <string.h>
/**
 * print_rev - print string in reverse
 * @s: the string
 */
void print_rev(char *s)
{
	int c = strlen(s) - 1;

	while (c >=0)
	{
		_putchar(s[c]);
		c--;
	}
	_putchar('\n');
}
