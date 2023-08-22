#include "main.h"

/**
 * handle_bin - prints a num in base 2
 * @list: num to print
 * Return: len of the num
 **/
int handle_bin(va_list list)
{
	char *c;
	int len;

	c = int_ascii(va_arg(list, unsigned int), 2);

	len = print(c);

	return (len);
}
