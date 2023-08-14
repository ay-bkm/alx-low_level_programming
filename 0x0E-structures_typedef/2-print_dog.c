#include "main.h"
#include <stdio.h>
/**
 * print_dog - Prints the contents of a struct dog
 * @d: A pointer to the struct dog to print
 *
 * Description: This function prints the contents of a struct dog in the
 * specified format. If any of the elements of the struct are NULL, the
 * function prints (nil) instead of the value of that element. If the
 * pointer d is NULL, the function prints nothing.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;
	printf("Name: %s\n", d->name ? d->name : "(nil)");
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
