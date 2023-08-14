#include "dog.h"
/**
 * init_dog - initialization
 * @d: pointer to a variable
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 * Return: nothing
 */
void init_dog(struct * d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;
	d->name = name;
	d->age = age;
	d->owner = owner;
}
