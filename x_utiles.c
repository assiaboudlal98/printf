#include "main.h"

/**
 * is_printable - Evaluating  when char  printable
 * @c: Char for evaluating.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifing if a char is  digit
 * @c: Char for  evaluating
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_sz_number - For casting a number to the specified size
 * @num: Number for casting.
 * @sz: Number indicats the type casts.
 *
 * Return: Casted value of num
 */
long int convert_sz_number(long int num, int sz)
{
	if (sz == S_LONG)
		return (num);
	else if (sz == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_sz_unsgnd - For casting a number to the specified size
 * @num: Number for  casting
 * @sz: Number indicats type to cast it
 *
 * Return: Casted value of num
 */
long int convert_sz_unsgnd(unsigned long int num, int sz)
{
	if (sz == S_LONG)
		return (num);
	else if (sz == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
