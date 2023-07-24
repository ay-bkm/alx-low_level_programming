#include "main.h"
#include <string.h>
#include <stdio.h>
/**
 * print_array - prints n elements of array
 * @a: array
 * @n: number of elements in array
 */
void print_array(int *a, int n)
{
	int i;
	int n = strlen(a) - 1;

	for (i = 0; i < n; i++)
	{
		if (i < n)
		{
			printf("%d, ", i);
		}
		else if
		{
			printf("%d", i);
		}
	}
	printf("\n");
}
