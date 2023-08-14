#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * init_dog - a function that initialize a variable of type struct dog.
 * @d: pointer to structure
 * @name: name of first member.
 * @age: age of second member.
 * @owner: third member
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		d = malloc(sizeof(struct dog));
	}
	d->name = name;
	d->age = age;
	d->owner = owner;
}
