#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_char - responsible for printing a char
 * @c: character to be printed
 * Return: 1 (no of char printed in this case 1)
 */
int print_char(va_list c)
{
	char ch = (char)va_arg(c, int);

	_putchar(ch);
	return (1);
}
/**
 * print_str - function to print a string
 * @s: string to be printed
 * Return: number of characters to be printed in the string
 */
int print_str(va_list s)
{
	int i;
	char *str = va_arg(s, char*);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
