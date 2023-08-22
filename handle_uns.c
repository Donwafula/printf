#include "main.h"

/**
 * handle_uns - Prints unsigned int
 * @list: number to print
 * Return: len of the number
 **/
int handle_uns(va_list list)
{
	char *c;
	int n;

	c = int_ascii(va_arg(list, unsigned int), 10);

	n = print((c != NULL) ? c : "NULL");

	return (n);
}
