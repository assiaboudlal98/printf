#include "main.h"
<<<<<<< HEAD

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];
=======
/**
 *_printf - function that prints char and str and prcent,
 * @format: pointer variable,
 * Return: return the value of cnt_x,
 */
int _printf(const char *format, ...)
{
	va_list args_arx;
	int cnt_x;
>>>>>>> 6e5ead58cb67a8c92e5a247dc0aef1cb57884b1b

	if (format == NULL)
		return (-1);

<<<<<<< HEAD
	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

=======
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
>>>>>>> 6e5ead58cb67a8c92e5a247dc0aef1cb57884b1b
