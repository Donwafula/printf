// number_functions.c

#include "main.h"

// Helper function to print an unsigned number with the given base
int print_unsigned_number(unsigned int num, int base)
{
     // Handle the digits of the number
     int printed_chars = 0;
     if (num == 0)
     {
          printed_chars += _myputchar('0');
     }
     else
     {
          char buffer[20];
          int index = 0;
          while (num > 0)
          {
               int digit = num % base;
               buffer[index++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
               num /= base;
          }
          while (index > 0)
          {
               printed_chars += _myputchar(buffer[--index]);
          }
     }
     return printed_chars;
}

// Helper function to print a hexadecimal number (lowercase or uppercase)
int print_hexadecimal(unsigned int num, int uppercase)
{
     int base = (uppercase) ? 'A' : 'a';
     int printed_chars = 0;
     char buffer[20];
     int index = 0;
     if (num == 0)
     {
          printed_chars += _myputchar('0');
     }
     else
     {
          while (num > 0)
          {
               int digit = num % 16;
               buffer[index++] = (digit < 10) ? ('0' + digit) : (base + digit - 10);
               num /= 16;
          }
          while (index > 0)
          {
               printed_chars += _myputchar(buffer[--index]);
          }
     }
     return printed_chars;
}