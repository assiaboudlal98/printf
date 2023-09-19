#include "main.h"
/**
 * h_wrt_char - Prints a str,
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags.
 * @width: get width.
 * @prcs: precision specifier
 * @sz: Size specifier
 *
 * Return: Number of chars printed.
 */
int h_wrt_char(char c, char buffer[],
		int flg, int width, int prcs, int sz)
{
	int i = 0;
	char padd = ' ';

	UNUSED(prcs);
	UNUSED(sz);
	if (flg & F_ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;
		if (flg & F_MINUS)
			return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) + write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/**
 * write_nmbr - Prints a string,
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @width: get width.
 * @prcs: precision specifier
 * @sz: Size specifier
 * Return: Number of chars printed.
 */
int write_nmbr(int is_negative, int ind, char buffer[], int flg, int width, int prcs, int sz)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(sz);
	if ((flg & F_ZERO) && !(flg & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flg & F_PLUS)
		extra_ch = '+';
	else if (flg & F_SPACE)
		extra_ch = ' ';
	return (write_num(ind, buffer, flg, width, prcs, length, padd, extra_ch));
}
/**
 * wrt_nm - Write a number using,
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flg: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 * Return: Number of printed chars,
 */
int wrt_num(int ind, char buffer[], int flg, int width, int prec, int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flg & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flg & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flg & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) + write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}
/**
 * wrt_uns - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flg: Flags specifiers
 * @width: Width specifier
 * @prcs: Precision specifier
 * @sz: Size specifier
 * Return: Number of written chars.
 */
int wrt_uns(int is_negative, int ind, char buffer[], int flg, int width, int prcs, int sz)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(sz);

	if (prcs == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (prcs > 0 && prcs < length)
		padd = ' ';

	while (prcs > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';
		if (flg & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}
/**
 * wrt_ptr - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flg: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int wrt_ptr(char buffer[], int ind, int length,
		int width, int flg, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flg & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flg & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flg & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
