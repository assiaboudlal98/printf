#include "main.h"

/**
 * _printf - prints 
 * @format: string's format
 *
 * Return: number of bytes that have printed
 */
int _printf(const char *format, ...)
{
	int sum = 1;
	va_list jt;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(jt, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *) format; *p; p++)
	{
		init_params(&params, jt);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, jt);
		p = get_precision(p, &params, jt);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
				params.1_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, jt, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(jt);
	return (sum);
}



