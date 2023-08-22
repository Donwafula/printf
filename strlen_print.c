#include "main.h"


/**
 * _strlen - calculates the len of str
 * @s: str
 * Return: len
 **/
int _strlen(const char *s)
{
	int a;

	for (a = 0; s[a] != 0; a++)
		;

	return (a);
}

/**
 * print - prints char
 * @s: str
 * Return: str len
 */

int print(char *s)
{
	int a;

	for (a = 0; s[a] != '\0'; ++a)
		_myputchar(s[a]);

	return (a);
}
