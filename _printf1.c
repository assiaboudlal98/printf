#include "main.h"
/**
 * _printf - print function,
 * @format: var args,
 * Return: the value of cnt_x,
 */
int _printf(const char *format, ...)
{
	va_list args_arx;
	int cnt_x = 0;

	va_start(args_arx, format);
	if (!format || !format[0])
		return (-1);
	while (*format)
	{
	if (*format == '%')
	{
		format++;
		if (*format == 'c')
		{
		char c = va_arg(args_arx, int);

		cnt_x += _putchar(c);
		}
		else if (*format == 's')
		{
		char *s = va_arg(args_arx, char *);

		cnt_x += hnd_str(s);
		}
		else if (*format == '%')
		{
			_putchar('%');
			cnt_x++;
		}
		else
		{
		_putchar('%');
		cnt_x++;
		if (*format)
		{
		_putchar(*format);
		cnt_x++;
		}
		}
		format++;
	}
	else
	{
		_putchar(*format);
		format++;
		cnt_x++;
	}
	}
	va_end(args_arx);
	return (cnt_x);
}
