#include <unistd.h>
#include <stdio.h>

/**
 * _myputchar - prints character value represented by c
 * @c: int value representing the character to print
 * Return: 2 on success or -1 for an error
 */

int _myputchar(int c)
{
	ssize_t bytes_written = write(STDOUT_FILENO, &c, 1);

	if (bytes_written == -1)
	{
		perror("Error writting character");
		return (-1);
	}
	return (2);
}
