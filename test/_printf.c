#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: The format of the string.
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{	
	unsigned int i = 0, n = 0;

	while (format[i] != 0)
	{	
		if (format[i] == '%')
			n++;
		i++;
	}
	write(1, format, n);
	printf("We have %d formatters\n", n);
	return (n);
}
