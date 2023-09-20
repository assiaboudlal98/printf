#include "main.h"
/**
 * len_num - function (the lenght)
 * @num_ma: var integer,
 * Return: 0 if num '0'
 */
int len_num(int num_ma)
{
	if (num_ma == 0)
		return (0);
	return (1 + len_num(num_ma / 10));
}
/**
 * hnd_nbr - function that print num,
 * @num_ma: var integer,
 * Return: var cnt_x,
 */
int hnd_nbr(int num_ma)
{
	int cnt_x = 0;

	if (num_ma < 0)
		cnt_x++;
	cnt_x += len_num(num_ma);
	if (num_ma == -2147483647)
	{
		_putchar('-');
		_putchar('2');
		hnd_nbr(147483647);
	}
	else if (num_ma < 0)
	{
		_putchar('-');
		num_ma = -num_ma;
	}
	if (num_ma >= 10)
	{
		hnd_nbr(num_ma / 10);
		hnd_nbr(num_ma % 10);
	}
	else if (num_ma < 10)
	{
		_putchar(num_ma + '0');
	}
	return (cnt_x);
}
