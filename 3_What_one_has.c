#include <unistd.h>
#include "main.h"
#include "print_functions.h"

int print_char(char c)
{
     if (write(1, &c, 1) == 1)
          return 1; // Successfully wrote 1 character
     else
          return -1; // Failed to write character
}

int print_string(char *s)
{
     int printed_chars = 0;
     if (s == NULL)
          s = "(null)";
     while (*s)
     {
          printed_chars += print_char(*s);
          s++;
     }
     return printed_chars;
}

int print_uint(unsigned int n)
{
     int printed_chars = 0;
     if (n == 0)
          return print_char('0');

     char buffer[32]; // Buffer to hold the string representation of the number
     int i = 0;

     while (n > 0)
     {
          buffer[i++] = (n % 10) + '0';
          n /= 10;
     }

     while (i > 0)
     {
          printed_chars += print_char(buffer[--i]);
     }

     return printed_chars;
}

int print_octal(unsigned int n)
{
     // Implement printing octal numbers
     // and return the number of printed characters
}

int print_hex(unsigned int n, int uppercase)
{
     // Implement printing hexadecimal numbers
     // and return the number of printed characters
}
