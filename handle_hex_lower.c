#include "main.h"

/**
 * handle_hex_lower - print a num in hexadecimal format
 * @list: num
 * Return: len
 **/
int handle_hex_lower(va_list list)
{
	char *c;
	int len;

	c = int_ascii(va_arg(list, unsigned int), 16);

	len = print((c != NULL) ? c : "NULL");

	return (len);
}
