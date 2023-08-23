#include <unistd.h>
#include "main.h"
#include "print_functions.h"

int _myputchar(char c)
{
     if (write(1, &c, 1) == 1)
          return 1; /* Successfully wrote 1 character */
     else
          return -1; /* Failed to write character */
}

int print_char(char c)
{
     return _myputchar(c);
}

int print_string(char *s)
{
     int printed_chars = 0;
     while (*s)
     {
          printed_chars += _myputchar(*s);
          s++;
     }
     return printed_chars;
}

int print_int(int num)
{
     int printed_chars = 0;
     /* Handle negative numbers */
     if (num < 0)
     {
          printed_chars += _myputchar('-');
          num = -num;
     }
     /* Convert integer to string and print each digit */
     if (num == 0)
     {
          printed_chars += _myputchar('0');
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
               printed_chars += _myputchar('0' + reversed % 10);
               reversed /= 10;
          }
     }
     return printed_chars;
}

int print_S(char *s)
{
     int printed_chars = 0;
     while (*s)
     {
          if (*s >= 32 && *s < 127)
          {
               printed_chars += _myputchar(*s);
          }
          else
          {
               printed_chars += _myputchar('\\');
               printed_chars += _myputchar('x');
               if (*s < 16)
                    printed_chars += _myputchar('0');
               printed_chars += print_hex(*s);
          }
          s++;
     }
     return printed_chars;
}

int print_hex(unsigned int num)
{
     int printed_chars = 0;
     if (num > 15)
          printed_chars += print_hex(num / 16);
     printed_chars += _myputchar("0123456789ABCDEF"[num % 16]);
     return printed_chars;
}

int print_pointer(void *ptr)
{
     int printed_chars = 0;
     printed_chars += _myputchar('0');
     printed_chars += _myputchar('x');
     printed_chars += print_hex((unsigned long int)ptr);
     return printed_chars;
}