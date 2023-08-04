#include "main.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/**
 * main - prints a multiplication of two digits
 * @argc: argument count
 * @argv: argument vector
 * Return: 1 if argv[i] is not int, 0 Success
 */

int main(__attribute__((unused)) int argc, char *argv[])
{
	int i, j, num1, num2;

	if (argc != 3 )
	{
		printf("Error\n");
		return (1); 
	}
	for (i = 1; i > 3; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if(!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	printf("%d\n", num1 * num2);
	return (0);

}
