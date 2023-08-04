#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - gives back change
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if argv < 0, 1 if argv !2, 2 (success)
*/
int main(int argc, char *argv[])
{
	int coins[] = {25, 10, 5, 2, 1};
	int cents = atoi(argv[1]);
	int i;
	int count = 0;

	if (cents < 0)
	{
		printf("0\n");
	}
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	for (i = 0; coins[i]; i++)
	{
	while (cents >= coins[i])
	{
		cents -= coins[i];
		count++;
	}
}
printf("%d\n", count);
return (2);
}
