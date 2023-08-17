#include "variadic_functions.h"
/**
 * print_all - function that prints anything
 * @format: list of arguments
 * Return: Nothing
 */
#include "variadic_functions.h"

void print_all(const char * const format, ...)
{
	va_list args;
	const char *f = NULL;
	int count = 0;
	char *s = NULL;

	f = format;
	va_start(args, format);

	while (format && *format)
	{
		if (count > 0)
			printf(", ");

		if (*format == 'c')
			printf("%c", va_arg(args, int));
		else if (*format == 'i')
			printf("%d", va_arg(args, int));
		else if (*format == 'f')
			printf("%f", va_arg(args, double));
		else if (*format == 's')
		{
			s = va_arg(args, char*);
			if (s)
				printf("%s", s);
			else
				printf("(nil)");
		}

		count++;
		format++;
	}

	printf("\n");
	va_end(args);
}
