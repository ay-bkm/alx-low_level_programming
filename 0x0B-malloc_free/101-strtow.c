#include <stdlib.h>
#include <stdio.h>

/**
 * word_count - counts the number of words in a string
 * @str: the string to count
 *
 * Return: the number of words in the string
 */
int word_count(char *str)
{
		int i, wc, state;

		wc = 0;
		state = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			state = 0;
		}
		else if (state == 0)
		{
			state = 1;
			wc++;
		}
	}
	return (wc);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	int i, j, k, l, wc;
	char **w;

	wc = word_count(str)

	if (str == NULL || str[0] == '\0' || wc == 0)
		return (NULL);

	w = malloc(sizeof(char *) * (wc + 1));
	if (w == NULL)
		return (NULL);

	for (i = 0, l = 0; i < wc; i++)
	{
		while (str[l] == ' ')
			l++;
		for (j = l; str[j] != ' ' && str[j]; j++)
			return;
		w[i] = malloc(sizeof(char) * (j - l + 1));
		if (w[i] == NULL)
		{
			while (--i >= 0)
				free(w[i]);
			free(w);
				return (NULL);
		}
		for (k = 0; l < j; l++, k++)
			w[i][k] = str[l];
		w[i][k] = '\0';
		}
		w[i] = NULL;
		return (w);
}
