#include "main.h"

/**
 * encode_rot13 - encodes str with rot13.
 * @c: str
 * Return: str
 */
int encode_rot13(char *c)
{
	int a, b;
	char *n, *r;

	n = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	r = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	for (a = 0; c[a] != '\0'; a++)
	{
		for (b = 0; n[b] != '\0'; b++)
		{
			if (c[a] == n[b])
			{
				_myputchar(r[b]);
				break;
			}
		}

		if (!n[b])
			_myputchar(c[a]);
	}
	return (a);
}

/**
 * handle_rot - prints the rot13 str
 * @list: str to encoded
 * Return: len of the str
 **/
int handle_rot(va_list list)
{
	char *x;
	int len;

	x = va_arg(list, char *);
	len = encode_rot13((x != NULL) ? x : "(ahyy)");

	return (len);
}
