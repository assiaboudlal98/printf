#include "main.h"
/**
 * h_print - looking for its type it prints the argument
 * @jtn: to prints the arguments and format the string.
 * @list: argument's list to be printed
 * @ind: ind.
 * @buffer: array's buffer for handling print.
 * @flg: for Calculating active flags
 * @wdt: get wdt.
 * @prcs: for Precision specification
 * @sz: telling the size
 * Return: 1 or 2;
 */
int h_print(const char *jtn, int *ind, va_list list, char buffer[],
	int flg, int wdt, int prcs, int sz)
{
	int i, unknown_eln = 0, prt_char = -1;
	jtn_s jtn_types[] = {
		{'c', pr_char}, {'s', print_string}, {'%', pr_prcnt},
		{'i', print_int}, {'d', print_int}, {'b', pr_binary},
		{'u', print_uns}, {'o', print_oct}, {'x', pr_hex},
		{'X', pr_hex_upp}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; jtn_types[i].jtn != '\0'; i++)
		if (jtn[*ind] == jtn_types[i].jtn)
			return (jtn_types[i].fn(list, buffer, flg, width, prcs, sz));

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

