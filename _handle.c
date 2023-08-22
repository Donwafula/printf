#include "main.h"

/**
 * _handle - format handler
 * @str: str format
 * @list: args
 * Return: Total size of args and base str
 **/
int _handle(const char *str, va_list list)
{
	int len, i, a;

	len = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == '%')
		{
			a = percent_handler(str, list, &i);
			if (a == -1)
				return (-1);

			len += a;
			continue;
		}

		_myputchar(str[i]);
		len = len + 1;
	}


	return (len);
}

/**
 * percent_handler - Controller for percent format
 * @str: String format
 * @list: List of arguments
 * @i: Iterator
 *
 * Return: Size of the numbers of elements printed
 **/
int percent_handler(const char *str, va_list list, int *i)
{
	int len, j, n_form;
	format formats[] = {
		{'s', handle_str}, {'c', handle_char},
		{'d', handle_int}, {'i', handle_int},
		{'b', handle_bin}, {'u', handle_uns},
		{'o', handle_oct}, {'x', handle_hex_lower},
		{'X', handle_hex_upper}, {'p', handle_ptr},
		{'r', handle_str_rev}, {'R', handle_rot}
	};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		_myputchar('%');
		return (1);
	}

	n_form = sizeof(formats) / sizeof(formats[0]);
	for (len = j = 0; j < n_form; j++)
	{
		if (str[*i] == formats[j].type)
		{
			len = formats[j].f(list);
			return (len);
		}

	}

	_myputchar('%'), _myputchar(str[*i]);

	return (2);
}
