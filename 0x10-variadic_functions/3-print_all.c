#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_all - Custom print function for various data types.
 * @format: List of argument types.
 * Return: void
*/
void print_all(const char * const format, ...)
{
    va_list args;
    int i = 0;
    char c;
    float f;
    char *s;
    
    va_start(args, format);
    
    while (format && format[i])
    {
        switch (format[i])
        {
            case 'c':
                c = va_arg(args, int);
                printf("%c", c);
                break;
            case 'i':
                printf("%d", va_arg(args, int));
                break;
            case 'f':
                f = va_arg(args, double);
                printf("%f", f);
                break;
            case 's':
                s = va_arg(args, char *);
                if (s == NULL)
                    printf("(nil)");
                else
                    printf("%s", s);
                break;
        }
        
        if (format[i + 1] != '\0' && (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's'))
            printf(", ");
        
        i++;
    }
    
    va_end(args);
    printf("\n");
}
