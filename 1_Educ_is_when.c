#include "main.h"

/**
 * handle_int - printa an int base 10 to stdout
 * @list: int to print
 * Return: Length of the int in decimal
 **/
int handle_int(va_list list)
{
	char *int_c;
	int len;

	int_c = int_ascii(va_arg(list, int), 10);

	len = print((int_c != NULL) ? int_c : "NULL");

	return (len);
}
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
