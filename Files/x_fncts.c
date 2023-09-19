#include "main.h"
/**
 * pr_char - Pr char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @width: Width
 * @prcs: Precision sp
 * @sz: Size specif
 * Return: Number of chars printed
 */
int pr_char(va_list types, char buffer[],
		int flg, int width, int prcs, int sz)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flg, width, prcs, sz));
}
/**
 * pr_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calc active flg
 * @width: get width.
 * @prcs: Prcs specif
 * @sz: Size spec
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
		int flg, int width, int prcs, int sz)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(width);
	UNUSED(prcs);
	UNUSED(sz);
	if (str == NULL)
	{
		str = "(null)";
		if (prcs >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (prcs >= 0 && prcs < length)
		length = prcs;

	if (width > length)
	{
		if (flg & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * pr_prcnt - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @width: get width.
 * @prcs: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int pr_prcnt(va_list types, char buffer[],
	int flg, int width, int prcs, int sz)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(width);
	UNUSED(prcs);
	UNUSED(sz);
	return (write(1, "%%", 1));
}

/************************* INT *************************/
/**
 * pr_int - Print int,
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @width: get width.
 * @prcs: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int pr_int(va_list types, char buffer[],
	int flg, int width, int prcs, int sz)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, sz);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flg, width, prcs, sz));
}

/************************* BINARY *************************/
/**
 * pr_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @width: get width.
 * @prcs: Precision specification
 * @sz: Size specifier
 * Return: Numbers of char printed.
 */
int pr_binary(va_list types, char buffer[],
	int flg, int width, int prcs, int sz)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(width);
	UNUSED(prcs);
	UNUSED(sz);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
