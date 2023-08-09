#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * word_count - counts the number of words in a string
 * @str: the string to count
 *
 * Return: the number of words in the string
 */
int word_count(char *str)
{
	int idx, word_count, state;
	word_count = 0;
	state = 0;

	for (idx = 0; str[idx]; idx++)
	{
		if (str[idx] == ' ')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			word_count++;
		}
	}
	return (word_count);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	int i, j, k, l, word_count;
	char **words;

	word_count == word_count(str);

	if (str == NULL || str[0] == '\0' || word_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0, l = 0; i < word_count; i++)
	{
		while (str[l] == ' ')
			l++;
		for (j = l; str[j] != ' ' && str[j]; j++)
			;
		words[i] = malloc(sizeof(char) * (j - l + 1));
		if (words[i] == NULL)
		{
			while (--i >= 0)
				free(words[i]);
			free(words);
			return (NULL);
		}
		for (k = 0; l < j; l++, k++)
			words[i][k] = str[l];
		words[i][k] = '\0';
	}
	words[i] = NULL;
	return (words);
}
