#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: argumet's list
 * @buffer: it handles to print
 * @flg:  Calculates active flg
 * @wdt: get wdt
 * @prcs: Precision specification
 * @sz: Size looking
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(wdt);
	UNUSED(sz);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(prcs);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		padd = '0';
	if (flg & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		wdt, flg, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: arguments
 * @buffer: it handles to print
 * @flg:  Calculates active flg
 * @wdt: get wdt
 * @prcs: Precision specification
 * @sz: Sz specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flg);
	UNUSED(wdt);
	UNUSED(prcs);
	UNUSED(sz);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints another string.
 * @types: argument's list
 * @buffer: it  handles to print
 * @flg:  Calculates active flg
 * @wdt: get width
 * @prcs: Precision specification
 * @sz: Size
 * Return: Numbers of characters
 */

int print_reverse(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wdt);
	UNUSED(sz);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(prcs);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: arguments list
 * @buffer: it  handlez to print
 * @flg:  Calculates active flags
 * @wdt: get width
 * @prcs: Precision specification
 * @sz: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flg);
	UNUSED(wdt);
	UNUSED(prcs);
	UNUSED(sz);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
