#include "main.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/**
 * main - prints a addition of positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 1 if argv[i] is not int, 0 Success
 */

int main(int argc, char **argv)
{
	int i, j, num, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}
		num = atoi(argv[i]);
			sum += num;
	}
	printf("%d\n", sum);
	return (2);
}
