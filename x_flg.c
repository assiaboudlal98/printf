#include "main.h"

/**
 * x_flg - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int x_flg(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int k, curr_i;
	int flg = 0;
	const char FLG_P[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLG_y[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (etg_i = *i + 1; format[etg_i] != '\0'; etg_i++)
	{
		for (k = 0; FLG_CH[k] != '\0'; k++)
			if (format[etg_i] == FLG_CH[j])
			{
				flg |= FLG_ARR[j];
				break;
			}

		if (FLG_CH[k] == 0)
			break;
	}

	*i = etg_i - 1;

	return (flg);
}
