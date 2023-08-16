#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - iterates over and array and calls a fucntion
 * @array: The array to iterate
 * @size: size of the array
 * @action: pointer to the function
 * Return: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	for (i = 0; i < size; i++)
		action(array[i]);
}
