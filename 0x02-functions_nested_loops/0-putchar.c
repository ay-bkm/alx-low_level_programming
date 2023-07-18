#include <stdio.h>
/**
 * main - prints "_putchar"
 * Return: 0 Always (Success)
 */
 int main(void) 
 {
     char _putchar[] = "_putchar";
     for (int i = 0; i <=8; i++)
     {
         putchar(_putchar[i]);
     }
     putchar('\n');
     return 0;
 }
