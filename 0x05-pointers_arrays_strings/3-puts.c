#include "main.h"
/**
 * _puts - prints a string
 * @str: character pointer
 */
void _puts(char *str)
{
	int c = 0;

	while (str[c] != '\0')
	{
		_putchar(str[c]);
		++c;
	}
	_putchar('\n');
}
