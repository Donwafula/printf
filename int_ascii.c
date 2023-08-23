#include "main.h"

/**
 * int_ascii - converts int to ascii value
 * @number: num
 * @b: base 10
 * Return: char
 */
char *int_ascii(long int number, int b)
{
	static char buff[50];
	static char *my_arr;
	unsigned long a;
	char s, *c;

	my_arr = "0123456789abcdef";
	a = number;
	s = 0;
	if (number < 0)
	{
		a = -number;
		s = '-';
	}
	c = &buff[49];
	*c = '\0';
	do {
		*--c = my_arr[a % b];
		a /= b;
	} while (a != 0);
	if (s)
	{
		*--c = s;
	}
	return (c);
}
