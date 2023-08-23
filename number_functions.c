// number_functions.c
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
// Helper functions to print a hexadecimal number (lowercase or uppercase)
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

int is_lower(char);
char *str_upper(char *s);

/**
 * handle_hex_upper - prints a num in hexadecimal format
 * @list: num to print
 * Return: len
 */
int handle_hex_upper(va_list list)
{
	char *c;
	int len;

	c = int_ascii(va_arg(list, unsigned int), 16);
	c = str_upper(c);

	len = print((c != NULL) ? c : "NULL");

	return (len);
}

/**
 * is_lower - check if the charis in lowercase
 * @c: char
 * Return: 1 or 0
 **/
int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * str_upper - change the str to uppercase
 * @s: str
 * Return: str uppercase
 **/
char *str_upper(char *s)
{
	int a;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (is_lower(s[a]))
		{
			s[a] = s[a] - 32;
		}
	}

	return (s);
}
