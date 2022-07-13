#include "main.h"
<<<<<<< HEAD
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
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
=======
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
>>>>>>> 286dcc46242c40ba4b7abd219734ef239db8664f
}
