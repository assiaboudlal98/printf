#include "main.h"

/*********************UNSIGNED Nmb************************/
/**
 * pr_uns - Pr unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flg
 * @wdt: get width
 * @prcs: Precision specifi
 * @sz: Size specif
 * Return: Number of chars printed.
 */
int pr_uns(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flg, wdt, prcs, sz));
}

/**********UNSIGNED Nmbr IN OCt  ****************/
/**
 * pr_oct - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wdt: get width
 * @prcs: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int pr_oct(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wdt);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flg & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flg, wdt, prcs, sz));
}

/************ UNSIGNED NUMB Hex**************/
/**
 * pr_hex - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wdt: get width
 * @prcs: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int pr_hex(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flg, 'x', wdt, prcs, sz));
}

/************* UNSIGNED NUMB UPP HEX**************/
/**
 * pr_hex_upp - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wdt: get width
 * @prcs: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int pr_hex_upp(va_list types, char buffer[],
	int flg, int wdt, int prcs, int sz)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flg, 'X', wdt, prcs, sz));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * pr_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flags
 * @flg_p: Calculates active flags
 * @wdt: get width
 * @prcs: Precision specification
 * @sz: Size specifier
 * @sz: Size specification
 * Return: Number of chars printed
 */
int pr_hexa(va_list types, char map_to[], char buffer[],
	int flg, char flg_p, int wdt, int prcs, int sz)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wdt);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flg & F_HASH && init_num != 0)
	{
		buffer[i--] = flg_p;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flg, wdt, prcs, sz));
}
