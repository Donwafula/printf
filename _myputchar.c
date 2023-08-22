#include "main.h"
#include <unistd.h>
#include <stdio.h>
int buffer(char c);

/**
 * _myputchar - writes c to stdout
 * @c: char to print
 * Return: On success 1 or -1
 */
int _myputchar(char c)
{
	return (buffer(c));
}

/**
 * buffer - Saves c in a buffer
 * @c: Cha
 * Return: 1
 **/
int buffer(char c)
{
	static char write_buffer[1024];
	static int a;

	if (c == -1 || a == 1024)
	{
		write(1, write_buffer, a);
		a = 0;
	}

	if (c != -1)
		write_buffer[a++] = c;

	return (1);
}
