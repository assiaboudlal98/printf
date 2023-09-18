#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
int _printf(const char *format, ...)
{
	va_list args_arx;
	int cnt_x;

	va_start(args_arx, format);
	cnt_x = 0;

	while (*format)
	{
		if(*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':{
					char c = va_arg(args_arx, int);
					putchar(c);
					cnt_x++;
					break;
					 }
				case 's':{
					char *s = va_arg(args_arx, int);
					while (*s)
						 {
							 putchar(*s);
							 s++;
							 cnt_x++;
						 }
					break;
					 }
				case '%':{
					putchar('%');
					cnt_x++;
					break;
					 }
				default:{
					break;
					}
			}
		}
		else
		{
			putchar(*format);
			cnt_x++;
		}
		format++;
	}
	va_end(args_arx);
	return (cnt_x);
}

