#include <stdarg.h>
#include "main.h"
#include "print_functions.h"

int _printf(const char *format, ...)
{
     int printed_chars = 0;
     va_list args;
     va_start(args, format);

     while (*format)
     {
          if (*format == '%')
          {
               format++;           // Move past '%'
               if (*format == 'c') // Handle %c conversion specifier
               {
                    int c = va_arg(args, int);
                    printed_chars += print_char(c);
               }
               else if (*format == 's') // Handle %s conversion specifier
               {
                    char *s = va_arg(args, char *);
                    printed_chars += print_string(s);
               }
               else if (*format == 'd') // Handle %d conversion specifier
               {
                    int num = va_arg(args, int);
                    printed_chars += print_int(num);
               }
               else if (*format == 'i') // Handle %i conversion specifier (same as %d)
               {
                    int num = va_arg(args, int);
                    printed_chars += print_int(num);
               }
               else if (*format == 'S') // Handle %S conversion specifier
               {
                    char *s = va_arg(args, char *);
                    printed_chars += print_S(s);
               }
               else if (*format == 'p') // Handle %p conversion specifier
               {
                    void *ptr = va_arg(args, void *);
                    printed_chars += print_pointer(ptr);
               }
               else if (*format == '%') // Handle %% conversion specifier
               {
                    printed_chars += print_char('%');
               }
               else
               {
                    // Print the character as is if not a known specifier
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
