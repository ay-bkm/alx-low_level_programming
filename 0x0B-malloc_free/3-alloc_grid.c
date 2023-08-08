#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * alloc_grid - creates 2D array
 * @width: the width of the array
 * @height: the height of the array
 * Return: the 2D Array
 */
int **alloc_grid(int width, int height)
{

	int i, j;
	int **arr;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	arr = (int **)malloc(height * sizeof(int *));
	if (arr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		arr[i] = (int *)malloc(width * sizeof(int));
	if (arr[i] == NULL)
	{
		for (j = 0; j < i; j++)
		{
			free(arr[j]);
		}
		free(arr);
		return (NULL);
	}
	for (j = 0; j < width; j++)
	{
		arr[i][j] = 0;
	}
	}
	return (arr);
}
