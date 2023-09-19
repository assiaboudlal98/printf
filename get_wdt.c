#include "main.h"

/**
 * get_wdt - Calculates for the printing for wtd
 * @format: to prints the arguments and format the string
 * @i: argument's list to print.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_wdt(const char *format, int *i, va_list list)
{
	int etg_i;
	int wdt = 0;

	for (etg_i = *i + 1; format[etg_i] != '\0'; etg_i++)
	{
		if (is_digit(format[etg_i]))
		{
			wdt *= 10;
			wdt += format[etg] - '0';
		}
		else if (format[etg_i] == '*')
		{
			etg_i++;
			wdt = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = etg - 1;

	return (wdt);
}

