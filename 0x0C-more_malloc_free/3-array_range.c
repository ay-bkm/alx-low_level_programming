#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
* array_range - creates a range of int in an array
* @min: the minimun int
* @max: maximun int
* Return: allocated memory
 */
int *array_range(int min, int max)
{
	int length;
	int *mem;
	int i;

	length = max - min + 1;
	if (length < 0)
		return (NULL);
	mem = malloc(length * sizeof(int));
	if (mem == 0)
		return (NULL);
	for (i = 0; i < length; i++)
		mem[i] = min + i;
return (mem);
}
