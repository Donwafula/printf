#include "main.h"

/**
 * handle_char - prints char to stdout
 * @list: va_list.
 * Return: 1
 */

int handle_char(va_list list)
{
	int a;

	a = va_arg(list, int);
	_myputchar(a);
	return (1);
}
