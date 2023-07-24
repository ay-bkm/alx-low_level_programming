#include "main.h"
/**
 * swap_int - swaps value of two integers
 * @a: first value
 * @b: second value
 */
void swap_int(int *a, int *b)
{
	int x = *a;
	*a = *b;
	*b = x;
}
