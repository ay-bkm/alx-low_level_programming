#include "main.h"
/**
 * print_sign - prints the sign of a number
 * Return: 0 if n is zero
 * 1 if n is greater then zero
 * -1 if n is less than zero
 *  @n: is the checked int
 */
int print_sign(int n)
{
if (n > 0)
{
_putchar('+');
return (1);
}
else if (n == 0)
{
_putchar(48);
return (0);
}
else if (n < 0)
{
_putchar('-');
}
return (-1);
}
