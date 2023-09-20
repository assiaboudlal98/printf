#include "main.h"
/**
 * _printf - print function,
 * @format: var format str,
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
			cnt_x += _putchar(va_arg(args_arx, int));
		else if (*format == 's')
			cnt_x += hnd_str(va_arg(args_arx, char *));
		else if (*format == '%')
		{
			_putchar('%');
			cnt_x++;
		}
		else if (*format == 'd' || *format == 'i')
			cnt_x += hnd_nbr(va_arg(args_arx, int));
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
		_putchar(*format++);
		cnt_x++;
	}
	}
	va_end(args_arx);
	return (cnt_x);
}
