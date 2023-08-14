#include "dog.h"
#include <stdio.h>

/**
 * display_dog - Displays information about a dog
 * @d: A pointer to the struct dog to display
 *
 * Description: This function displays information about a dog, including itsnct
 * name, age, and owner. If any of the elements of the struct are NULL, the
 * function displays (nil) instead of the value of that element. If the
 * pointer d is NULL, the function displays nothing.
 */
void print_dog(struct dog *d)
{
    if (d == NULL)
        return;

    char *name = d->name ? d->name : "(nil)";
    char *owner = d->owner ? d->owner : "(nil)";

    printf("Name: %s\nAge: %f\nOwner: %s\n", name, d->age, owner);
}
