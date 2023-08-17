#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_op_func - executes needed fuction
 * @s: The operator
 * Return: pointer
 */
int (*get_op_func(char *s))(int, int)
{
	int i;

	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	for (i = 0; ops[i].op != NULL; i++)
	{
		if (*ops[i].op == *s && s[1] == '\0')
		{
			return (ops[i].f);
		}
	}
	return (NULL);
}
