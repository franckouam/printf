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

void print_string(char *str)
{
	int i = 0;
	do {
		_putchar( str[i]);
		i++;
	} while (str[i] != '\0');
}

/*void write_int(int n)
{
	int tmp = n, i = 0, j = 0; 
	while (n % 10 > 9)
	{
		i++;
		tmp = tmp % 10;
	}
	
	for (j = tmp; j > 0; j--)
		_putchar(48 + (n % (int)pow(10, tmp)));
	_putchar(48 + tmp);

}*/

/**
 * _printf - Produces output according to a format
 * @format: The format of the string.
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{	
	va_list ap;
	unsigned int j = 0, n = 0; /*i = 0;*/
	
	/*while (format[i] != '\0')
	{	
		if (format[i] == '%')
			n++;
		i++;
	}*/
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

			/*if (format[j + 1] == 'c')
				_putchar(va_arg(ap, int));
			else if (format[j + 1] == 's')
				print_string(va_arg(ap, char *));*/
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
