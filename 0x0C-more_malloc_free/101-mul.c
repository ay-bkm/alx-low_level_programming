#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * check_digit - check if str has non-digit char
 * @str: input string
 * Return: 0 (non-digit), 1 (fail)
 */
int check_digit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * string_length - return length str
 * @str: input string
 * Return: length of str (Success)
 */
int string_length(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * error_handler - error handler for main
 * Return: void
 */
void error_handler(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplication of argc and argv
 * @argc: argument number
 * @argv: arguments array vector
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, len, i, carry, digit1, digit2, *result, a = 0;

	num1 = argv[1], num2 = argv[2];
	if (argc != 3 || !check_digit(num1) || !check_digit(num2))
		error_handler();
	len1 = string_length(num1);
	len2 = string_length(num2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = num1[len1] - '0';
		carry = 0;
		for (len2 = string_length(num2) - 1; len2 >= 0; len2--)
		{
			digit2 = num2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			putchar(result[i] + '0');
	}
	if (!a)
	putchar('0');
	putchar('\n');
	free(result);
	return (0);
}
