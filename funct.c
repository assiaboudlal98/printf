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
 * hnd_str - function print str,
 * @s: pointer str,
 * Return: the value of i,
 */
int hnd_str(char *s)
{
	int i = 0;

	if (s == NULL)
	{
		return (hnd_str("(null)"));
	}
	while (s[i])
	{
	_putchar(s[i]);
	i++;
	}
	return (i);
}
