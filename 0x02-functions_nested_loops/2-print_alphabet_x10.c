#include "main.h"
/**
 * print_alphabet_x10 - prints all alphabets 10 times
 */
void print_alphabet_x10(void)
{
char letter;
int i;
while (i <= 10)
{
i++;
for (letter = 'a'; letter <= 'z'; letter++)
{
_putchar(letter);
}
}
}
