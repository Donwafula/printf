#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format string with zero or more directives
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
  int len;
  va_list args;
  
  if (format == NULL)
		return (-1);

  len = _strlen(format);
	if (len <= 0)
		return (0);

	va_start(args, format);
	len = _handle(format, args);

	_putchar(-1);
	va_end(args);

	return (len);
}
