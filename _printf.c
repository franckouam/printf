#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints an array of string characters
 * @str: the variable to print
 *
 */

void print_string(char *str)
{
	int i = 0;

	do {
		_putchar(str[i]);
		i++;
	} while (str[i] != '\0');
}

/**
 * _printf - Produces output according to a format
 * @format: The format of the string.
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int j = 0, n = 0;

	va_start(ap, format);
	while (format[j] != '\0')
	{
		if (format[j] == '%')
		{
			switch (format[j + 1])
			{
				case 'c':
					_putchar(va_arg(ap, int));
					break;
				case 's':
					print_string(va_arg(ap, char *));
					break;
				case '%':
					_putchar('%');
					break;
			}

			j++;
		}
		else
		{
			_putchar(format[j]);
		}
		j++;
	}
	va_end(ap);
	return (n);
}
