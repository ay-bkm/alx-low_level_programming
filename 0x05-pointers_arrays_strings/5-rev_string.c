#include "main.h"
#include <string.h>
/**
 * rev_string - reverses a string
 * @s: character pointer
 */
void rev_string(char *s)
{
	int length = strlen(s);
	int i, j;
	char bank;

	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		bank = s[i];
		s[i] = s[j];
		s[j] = bank;
	}
}		
