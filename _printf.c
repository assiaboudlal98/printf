#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
		format++;
		if (*format == 'c')
			count += print_char(args);
		else if (*format == 's')
			count += print_string(args);
		else if (*format == '%')
			count += print_percent(args);
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
