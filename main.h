#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int _myputchar(char c);
int handle_char(va_list list);
int handle_int(va_list list);
char *int_ascii(long int number, int b);
int handle_str_rev(va_list list);
int handle_str(va_list list);
int handle_uns(va_list list);
int encode_rot13(char *c);
int handle_rot(va_list list);
int _strcmp(char *s1, char *s2);
int handle_ptr(va_list list);
int handle_oct(va_list list);
int handle_bin(va_list list);
int print(char *s);
int _strlen(const char *s);
int handle_hex_lower(va_list list);
int is_lower(char);
char *str_upper(char *s);
int handle_hex_upper(va_list list);
int percent_handler(const char *str, va_list list, int *i);
int _handle(const char *str, va_list list);

/**
 * struct _format - Typedef struct
 *
 * @type: Format
 * @f: The function associated
 **/
typedef struct _format
{
	char type;
	int (*f)(va_list);
} format;

#endif
