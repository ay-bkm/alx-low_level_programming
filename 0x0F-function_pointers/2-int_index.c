#include <stdio.h>
#include "function_pointers.h"
/**
 * int_index - function that searches for integer
 * @array: an array of integers
 * @size: The size of the array
 * @cmp: pointer to the comparison function
 * Return: -1 if failed, if success: the index of the integer
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) == 0)
			return (-1);
		if (cmp(array[i]) != 0)
			return (i);
	}
	return (-1);
}
