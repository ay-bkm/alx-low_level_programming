#include "main.h"
/**
 *_strchr - locates a character in a stirng
 *@s: string of characters
 *@c: The character
 *Return: pointer to c, or NULL if not found
 */

char *_strchr(char *s, char c)
{
int i;
for (i = 0; s[i]; i++)
{
if (s[i] == c)
return (&s[i]);
}
if (c == '\0')
return (&s[i]);
return (0);
}
