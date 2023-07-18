#include "main.h"
/**
 * _islower - check is the char is lowercase
 * @c: is the checked char
 * Return: 1 if char is lowercase and 0 if otherwise
 */
int _islower(int c)
{
if (c >= 'a' && c <= 'z')
	return (1);
else
	return (0);
}
