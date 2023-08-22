#include "main.h"
#include <stdarg.h>
#include "print_functions.c"

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

	_myputchar(-1);
	va_end(args);

	return (len);
}
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; // Move past '%'
			if (*format == 'c')
			{
				int c = va_arg(args, int);
				printed_chars += print_char(c);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				printed_chars += print_string(s);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				printed_chars += print_int(num);
			}
			// Add more cases for other conversion specifiers
			else
			{
				// Print the character as is if not a known specifier
				printed_chars += _putchar('%');
				printed_chars += _putchar(*format);
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}

		format++;
	}

	va_end(args);
	return printed_chars;
}
