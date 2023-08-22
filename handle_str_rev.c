#include "main.h"

/**
 * handle_str_rev - prints str in reverse
 * @list: args
 * Return: length of the str
 */
int handle_str_rev(va_list list)
{
	int a, s;
	const char *c;

	c = va_arg(list, const char *);

	s = _strlen(c);

	for (a = s - 1; a >= 0; a--)
		_myputchar(c[a]);

	return (s);
}
