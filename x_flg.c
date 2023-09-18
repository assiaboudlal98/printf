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
	int j, curr_i;
	int flg = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLG_CH[j] != '\0'; j++)
			if (format[curr_i] == FLG_CH[j])
			{
				flg |= FLG_ARR[j];
				break;
			}

		if (FLG_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flg);
}
