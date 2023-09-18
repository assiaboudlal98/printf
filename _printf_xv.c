#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
#include <stdlib.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...)
{
	va_list args_arx;
	int cnt_x;

	va_start(args_arx, format);
	cnt_x = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
					char c = va_arg(args_arx, int);

					write(1, &c, 1);
					cnt_x++;
			}
			else if (*format == 's')
			{
					char *s = va_arg(args_arx, char*);

					while (*s)
					{
						write(1, &s, 1);
						s++;
						cnt_x++;
					}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				cnt_x++;
			}
		}
		else
		{
			write(1, format, 1);
			cnt_x++;
		}
		format++;
	}
	va_end(args_arx);
	return (cnt_x);
}
