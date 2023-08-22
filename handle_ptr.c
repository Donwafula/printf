#include "main.h"
#include <stdio.h>

int _strcmp(char *, char *);

/**
 * handle_ptr - prints a num in hexadecimal format
 * @list: num to print
 * Return: len of the num
 */
int handle_ptr(va_list list)
{
     char *c;
     int len;

     c = int_ascii(va_arg(list, unsigned long int), 16);

     if (!_strcmp(c, "0"))
          return (print("(nil)"));

     len = print("0x");

     if (!_strcmp(c, "-1"))
          len += print("ffffffffffffffff");
     else
          len += print(c);

     return (len);
}

/**
 * _strcmp - compares strs
 * @s1: str 1
 * @s2: str 2
 * Return: int
 **/
int _strcmp(char *s1, char *s2)
{
     int com;

     for (com = 0; s1[com] != '\0'; com++)
     {
          if (s1[com] != s2[com])
               return (s1[com] - s2[com]);
     }

     return (0);
}