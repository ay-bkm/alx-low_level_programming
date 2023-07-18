#include "main.h"
/**
 * _isalpha - checks if char is alphabet
 * @c: is the checked char
 * Return: 1 is char is alphabet otherwise 0
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
