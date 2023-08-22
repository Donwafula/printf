#include "main.h"

int is_lower(char);
char *str_upper(char *s);

/**
 * handle_hex_upper - prints a num in hexadecimal format
 * @list: num to print
 * Return: len
 */
int handle_hex_upper(va_list list)
{
     char *c;
     int len;

     c = int_ascii(va_arg(list, unsigned int), 16);
     c = str_upper(c);

     len = print((c != NULL) ? c : "NULL");

     return (len);
}
/**
 * is_lower - check if the charis in lowercase
 * @c: char
 * Return: 1 or 0
 **/
int is_lower(char c)
{
     return (c >= 'a' && c <= 'z');
}

/**
 * str_upper - change the str to uppercase
 * @s: str
 * Return: str uppercase
 **/
char *str_upper(char *s)
{
     int a;

     for (a = 0; s[a] != '\0'; a++)
     {
          if (is_lower(s[a]))
          {
               s[a] = s[a] - 32;
          }
     }

     return (s);
}
