#include "main.h"

/**
 * handle_oct - prints unsigned octal
 * @list: num to print
 * Return: len of num
 */
int handle_oct(va_list list)
{
	char *c;
	int len;

	c = int_ascii(va_arg(list, unsigned int), 8);

	len = print((c != NULL) ? c : "NULL");

	return (len);
}
