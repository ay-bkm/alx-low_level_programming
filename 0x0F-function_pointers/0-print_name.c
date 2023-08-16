#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - prints the name
 * @name: Pointer to the name
 * @f: function that prints the name
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
