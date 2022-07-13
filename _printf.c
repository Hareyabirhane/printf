#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int (*find_function(const char *format))(va_list)
{
	unsigned int i = 0;
	code_f find_f[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_dec},
		{"r", print_rev},
		{"b", print_bin},
		{"u", print_unsig},
		{"o", print_octal},
		{"x", print_x},
		{"X", print_X},
		{"R", print_rot13},
		{NULL, NULL}
	};

	while (find_f[i].sc)
	{
		if (find_f[i].sc[0] == (*format))
			return (find_f[i].f);
		i++;
	}
	return (NULL);
}
/**
*_printf -prints according to format.
*@format: a character string.
*
*Return: the number of character
*/
int _printf(const char *format, ...)
{
	int i, j, length, d_var, dvar_temp, dvar_length;
	int *dvar_digits;
	char *format_str;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);
	length = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case 'c':
				_putchar(va_arg(arg, int));
				i++;
				length++;
				break;
			case 'd':
				d_var = va_arg(arg, int);
				if (d_var < 0)
				{
					_putchar('-');
					length++;
					d_var = -d_var;
				}
				dvar_temp = d_var;
				while (dvar_temp)
				{
					dvar_length++;
					dvar_temp /= 10;
				}
				dvar_digits = malloc(dvar_length);
				j = 0;
				while (d_var)
				{
					dvar_digits[j] = d_var % 10;
					j++;
					d_var /= 10;
				}
				for (j = dvar_length - 1; j >= 0; j--)
				{
					_putchar(dvar_digits[j] + '0');
					length++;
				}
				free(dvar_digits);
				i++;
				break;
			case 'i':
				d_var = va_arg(arg, int);
				if (d_var < 0)
				{
					_putchar('-');
					length++;
					d_var = -d_var;
				}
				dvar_temp = d_var;
				while (dvar_temp)
				{
					dvar_length++;
					dvar_temp /= 10;
				}
				dvar_digits = malloc(dvar_length);
				j = 0;
				while (d_var)
				{
					dvar_digits[j] = d_var % 10;
					j++;
					d_var /= 10;
				}
				for (j = dvar_length - 1; j >= 0; j--)
				{
					_putchar(dvar_digits[j] + '0');
					length++;
				}
				free(dvar_digits);
				i++;
				break;
			case 's':
				format_str = va_arg(arg, char*);

				for (j = 0; format_str[j]; j++)
				{
					_putchar(format_str[j]);
					length++;
				}
				i++;
				break;
			case '%':
				_putchar('%');
				length++;
				i++;
				break;
			default:
				_putchar(format[i]);
				length = length + 1;
			}
		}
		else
		{
			_putchar(format[i]);
			length++;
		}
	}
	va_end(arg);
	return (length);
}
