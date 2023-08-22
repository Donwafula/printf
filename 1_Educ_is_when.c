#include <stdarg.h>
#include "main.h"

/* Helper function to print a character */
int _myputchar(char c);

/**
 * _printf - Custom printf function
 * @format: Format string with directives
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
     int printed_chars = 0;
     va_list args;

     va_start(args, format);

     while (*format)
     {
          if (*format == '%')
          {
               format++;           /* Move past '%' */
               if (*format == 'c') /* Handle %c conversion specifier */
               {
                    int c = va_arg(args, int);
                    printed_chars += _myputchar(c);
               }
               else if (*format == 's') /* Handle %s conversion specifier */
               {
                    char *s = va_arg(args, char *);
                    if (s == NULL)
                         s = "(null)"; /* Print (null) for NULL strings */
                    while (*s)
                    {
                         printed_chars += _myputchar(*s);
                         s++;
                    }
               }
               else if (*format == 'd' || *format == 'i') /* Handle %d and %i conversion specifiers */
               {
                    int num = va_arg(args, int);

                    /* Handle negative numbers */
                    if (num < 0)
                    {
                         _myputchar('-');
                         num = -num;
                    }

                    /* Handle the digits of the number */
                    int divisor = 1;
                    while (num / divisor > 9)
                    {
                         divisor *= 10;
                    }

                    while (divisor > 0)
                    {
                         _myputchar('0' + (num / divisor));
                         num %= divisor;
                         divisor /= 10;
                    }

                    printed_chars += _myputchar('%');
               }
               else
               {
                    /* Print the character as is if not a known specifier */
                    printed_chars += _myputchar('%');
                    printed_chars += _myputchar(*format);
               }
          }
          else
          {
               printed_chars += _myputchar(*format);
          }

          format++;
     }

     va_end(args);
     return printed_chars;
}

/* Helper function to print a character */
int _myputchar(char c)
{
     write(1, &c, 1);
     return 1;
}