#include "main.h"
/**
 * x_prc - precision calc,
 * @format : char variable,
 * @q: var list,
 * @li: list arg,
 * Return: return the value ofprcs,
 */
int x_prc(const char *format, int *q, va_list li)
{
	int etg_i = *q + 1;
	int prcs = -1;

	if (format[etg_i] != '.')
		return (prcs);
	prcs = 0;
	for (etg_i += 1;  format[etg_i] != '\0'; etg_i++)
	{
		if (is_digit(format[etg_i]))
		{
			prcs *= 10;
			prcs += format[etg_i] - '0';
		}
		else if (format[etg_i] == '*')
		{
			etg_i++;
			prcs = va_arg(li, int);
			break;
		}
		else
			break;
	}
	*i = etg_i - 1;
	return (prcs);
}
