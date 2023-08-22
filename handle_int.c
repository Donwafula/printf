#include "main.h"

/**
 * handle_int - prints an int base 10 to stdout
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