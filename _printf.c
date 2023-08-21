#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string with directives
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)

int printed_chars = 0;
va_list args;

va_start(args, format);

while (*format)
{
     if (*format == '%')
     {
          format++; // Move past '%'
          if (*format == 'c') // Handle %c conversion specifier
          {
               int c = va_arg(args, int);
               printed_chars += _putchar(c);
               }
               else if (*format == 's') // Handle %s conversion specifier
               {
                    char *s = va_arg(args, char *);
                    if (s == NULL)
                    s = "(null)"; // Print (null) for NULL strings
                    while (*s)
                    {
                         printed_chars += _putchar(*s);
                    s++;
                    }
                    }
            else if (*format == '%') // Handle %% conversion specifier
          {
               printed_chars += _putchar('%');
               }
            // Add more cases for additional conversion specifiers
          else
          {
                // Print the character as is if not a known specifier
               printed_chars += _putchar('%');
               printed_chars += _putchar(*format);
               }
               // You don't need to handle flags, width, precision, etc.
               }
               else
               {
                    printed_chars += _putchar(*format);
                    }
                    
                    format++;
}
va_end(args);
return printed_chars;

/**
 * _putchar - Output a character to stdout
 * @c: The character to output
 *
 * Return: 2 on success, -1 on failure
 */
int _putchar(char c)
{
     if (write(1, &c, 1) == 1)
        return 2; // Successfully wrote 1 character
     else
        return -1; // Failed to write character
}
