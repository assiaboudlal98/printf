#include "main.h"
/**
 *_printf - function that prints char and str and prcent,
 * @format: pointer variable,
 * Return: return the value of cnt_x,
 */
int _printf(const char *format, ...)
{
	va_list args_arx;
	int cnt_x;

	if (format == NULL)
		return (-1);

	va_start(args_arx, format);
	cnt_x = 0;
	while (*format)
	{
		if (*format != '%')
			cnt_x += write(1, format, 1);
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
				cnt_x += write(1, format, 1);
			else if (*format == 'c')
			{
				char c = va_arg(args_arx, int);

				cnt_x += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args_arx, char*);
				int s_tln = 0;

				while (s[s_tln] != '\0')
					s_tln++;
				write(1, s, s_tln);
				cnt_x += s_tln;
			}
		}
	format++;
	}
	va_end(args_arx);
	return (cnt_x);
}
