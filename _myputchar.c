#include <unistd.h>
#include <stdio.h>

/**
 * _myputchar - prints character value represented by c
 * @c: int value representing the character to print
 * Return: 0 on success or -1 for an error
 */

int _myputchar(int c)
{
	return (write_buffer(c));
}

/**
 * write_buffer - saves character in a buffer
 * @c: char to save to the buffer
 * Return: 1
 */

int write_buffer(char c)
{
	static char buffering[1024];
	static int a;

	if (c == -1 || a == 1024)
	{
		write(1, buffering, a);
		a = 0;
	}
	if (c != -1)
	{
		buffering[a++] = c;
	}
	return (1);
}
