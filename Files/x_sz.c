#include "main.h"
/**
 * x_sz - Calculates the sz,
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: return Prcs.
 */
int x_sz(const char *format, int *i)
{
	int etg_i = *i + 1;
	int sz = 0;

	if (format[et_i] == 'l')
		sz = S_LONG;
	else if (format[etg_i] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*i = etg_i - 1;
	else
		*i = etg_i;
	return (sz);
}
