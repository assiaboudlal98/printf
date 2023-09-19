#include "main.h"
/**
 * _putchar - Write a character to stdout
 * @c: The character to write
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_char - Print a character
 * @args: The arguments list
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}
/**
 * print_string - Print a string
 * @args: The arguments list
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	int count;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	count = 0;
	while (*str)
	{
	_putchar(*str);
	str++;
	count++;
	}
	return (count);
}
/**
 * print_percent - Print a percent character
 * @args: The arguments list
 *
 * Return: Number of characters printed
 */
int print_percent(__attribute__((unused)) va_list args)
{
	return (_putchar('%'));
}
