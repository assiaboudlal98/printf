#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
#include <stdlib.h>

#define BUFFER_SIZE 1024

static int write_buffer(char *buf, int *cnt_x)
{
	int bytes_written = write(1, buf, *cnt_x);
	*cnt_x = 0;
	return bytes_written;
}

int _printf(const char *format, ...)
{
	va_list args_arx;
	int cnt_x;
	char buf[BUFFER_SIZE];

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
					buf[cnt_x++] = c;
					if (cnt_x == BUFFER_SIZE)
						write_buffer(buf, &cnt_x);
					break;
					 }
				case 's':{
					char *s = va_arg(args_arx, char*);
					while (*s)
						 {
							 buf[cnt_x++] = *s;
							 s++;
							 if (cnt_x == BUFFER_SIZE)
								 write_buffer(buf, &cnt_x);
							 s++;
						 }
					break;
					 }
				case '%':{
					buf[cnt_x++] = '%';
					if (cnt_x == BUFFER_SIZE)
						write_buffer(buf, &cnt_x);
					break;
					 }
				default:{
					break;
					}
			}
		}
		else
		{
			buf[cnt_x++] = *format;
			if (cnt_x == BUFFER_SIZE)
				write_buffer(buf, &cnt_x);
		}
		format++;
	}
	va_end(args_arx);
	return (cnt_x);
}

