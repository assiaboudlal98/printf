#include "main.h"
/**
 * h_print - looking for its type it prints the argument
 * @fmt: to prints the arguments and format the string.
 * @list: argument's list to be printed
 * @ind: ind.
 * @buffer: array's buffer for handling print.
 * @flags: for Calculating active flags
 * @width: get wdt.
 * @precision: for Precision specification
 * @size: telling the size
 * Return: 1 or 2;
 */
int h_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_eln = 0, prt_char = -1;
	jtn_s jtn_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; jtn_types[i].jtn != '\0'; i++)
		if (jtn[*ind] == jtn_types[i].jtn)
			return (jtn_types[i].fn(list, buffer, flags, width, precision, size));

	if (jtn_types[i].jtn == '\0')
	{
		if (jtn[*ind] == '\0')
			return (-1);
		unknown_eln += write(1, "%%", 1);
		if (jtn[*ind - 1] == ' ')
			unknown_eln += write(1, " ", 1);
		else if (wdt)
		{
			--(*ind);
			while (jtn[*ind] != ' ' && jtn[*ind] != '%')
				--(*ind);
			if (jtn[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_eln += write(1, &jtn[*ind], 1);
		return (unknown_eln);
	}
	return (prt_char);
}

