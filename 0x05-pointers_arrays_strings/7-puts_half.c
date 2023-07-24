#include "main.h"
#include <string.h>
/**
 * puts_half - prints half of the string
 * @str: the string
 */
void puts_half(char *str)
{
	int length = strlen(str);
	int n = length / 2;
	int i = 0;

	if (length % 2 != 0)
	{
	n = (length + 1) / 2;
	}
	for (i = n; i <= length; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
