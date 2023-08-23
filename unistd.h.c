#include <stdarg.h>
#include <unistd.h> // For write function
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
               format++;
               // Handle %c conversion specifier
               if (*format == 'c')
               {
                    int c = va_arg(args, int);
                    printed_chars += print_char(c);
               }
               // Handle %s conversion specifier
               else if (*format == 's')
               {
                    char *s = va_arg(args, char *);
                    printed_chars += print_string(s);
               }
               // Handle %d and %i conversion specifiers
               else if (*format == 'd' || *format == 'i')
               {
                    int num = va_arg(args, int);
                    printed_chars += print_int(num);
               }
               // ...
          }
          else
          {
               printed_chars += print_char(*format);
          }

          format++;
     }

     va_end(args);
     return printed_chars;
}