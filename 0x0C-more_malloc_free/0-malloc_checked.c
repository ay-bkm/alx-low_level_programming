#include "main.h"
#include <stdlib.h>
/**
 * malloc_checked - checks malloc
 * @b: size
 * Return: pointer to memory
*/
void *malloc_checked(unsigned int b) {
	void *s;
	s = malloc(b);
	
	if (s == NULL)
		exit(98);

return ((void *)s);
}
