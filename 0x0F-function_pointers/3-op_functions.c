#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - prints the sum of two int
 * @a: The first integer
 * @b: The second integer
 * Return: The sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - prints the difference between teo int
 * @a: The first integer
 * @b: The second integer
 * Return: The difference between a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - prints the multiplication of two integers
 * @a: The first integer
 * @b: The second integer
 * Return: The multiplication of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - prints result of division
 * @a: The first integer
 * @b: The second integer
 * Return: result of division (a / b)
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - Remainder from division
 * @a: The first integer
 * @b: The second integer
 * Return: remainder from (a / b)
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
