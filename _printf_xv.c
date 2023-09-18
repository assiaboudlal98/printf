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
	char *str;

	va_start(args_arx, format);
	cnt_x = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':{
					char c = va_arg(args_arx, int);

					cnt_x += write(1, &c, 1);
					break;
				}
				case 'd':
				case 'i':{
					int num = va_arg(args_arx, int);
					char numt[20];
					int numln;

					numln = snprintf(numt, sizeof(numt), "%d", num);
					cnt_x += write(1, numt, numln);
					break;
				}
				case 's':{
					str = va_arg(args_arx, char*);

					while (*str)
					{
						cnt_x += write(1, &str, 1);
						str++;
					}
					break;
				}
				case '%':{
				cnt_x += write(1, "%", 1);
				break;
				}
			}
		}
		else
			cnt_x += write(1, format, 1);
		format++;
	}
	va_end(args_arx);
	return (cnt_x);
}
