#include "main.h"

/**
 * handle_str - prints str to stdout
 * @list: list.
 * Return: str len.
 */

int handle_str(va_list list)
{
	char *c;
	int len;

	c = va_arg(list, char*);
	len = print((c != NULL) ? c : "(null)");

	return (len);
}
