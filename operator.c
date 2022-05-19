#include "main.h"

/**
 * print_c - responsible for printing characters
 * @valist: arguments passed
 * Return: 1 after character is passed
 */

int print_c(va_list valist)
{
	_write(va_arg(valist, int));
	return (1);
}

/**
 * print_s - print the string
 * @valist: arguments
 * Return: number of characters printed
 */

int print_s(va_list valist)
{
	int a;
	char *string;

	string = va_arg(valist, char *);

	if (string == NULL)
	{
	}
	for (i = 0; string[a] != '\0'; a++)
	{
		_write(string[a]);
	}
	return (a);
}
/**
 * print_per - prints the percebtage sign
 * @valist: arguments
 * Return: the starting point of functiom
 */

int print_per(__attribute__((unused))va_list valist)
{
	_write('%');
	return (1);
}

/**
 * print_i - carries out function of i
 * @valist: arguments
 * Return: statrting point of function
 */
int print_i(va_list valist)
{
	int m;
	int length;
	unsigned int num;

	m = va_arg(valist, int);

	if (m < 0)
	{
		length += _write('_');
		num = m * -1;
	}
	else
		num = m;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		length += _write('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (length);
}
