#include <stdarg.h>
#include <unistd.h> // For write function
#include "main.h"
#include "print_functions.h"

/* Function to print a single character */
int print_char(char c)
{
     if (write(1, &c, 1) == 1)
          return 1; /* Successfully wrote 1 character */
     else
          return -1; /* Failed to write character */
}

/* Function to print a string */
int print_string(const char *s)
{
     int count = 0;
     while (*s)
     {
          count += print_char(*s);
          s++;
     }
     return count;
}

/* Function to print an integer */
int print_int(int num)
{
     int count = 0;
     /* Handle negative numbers */
     if (num < 0)
     {
          count += print_char('-');
          num = -num;
     }
     /* Convert integer to string and print each digit */
     if (num == 0)
     {
          count += print_char('0');
     }
     else
     {
          int reversed = 0;
          while (num > 0)
          {
               reversed = reversed * 10 + num % 10;
               num /= 10;
          }
          while (reversed > 0)
          {
               count += print_char('0' + reversed % 10);
               reversed /= 10;
          }
     }
     return count;
}

/* You can define similar functions for other conversions (print_dec, print_rev, etc.) */
/* ... */

/* In your _printf function, you can use these functions like this: */

int _printf(const char *format, ...)
{
     /* ... */
     else if (*format == 'c')
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
     /* ... */
}