#include <stdio.h>
#include <stdarg.h>
/**
 * sum_them_all - sums all the parameters
 * @n: number of parameters
 * Return: sum.
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum;
	va_list args;

	sum = 0;
	if (n == 0)
		return (0);

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return (sum);
}
