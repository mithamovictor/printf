#include "main.h"

/**
 * print_char - responsible for printing a char
 * @c: character to be printed
 * Return: 1 (no of char printed in this case 1)
 */
int print_char(va_list c)
{
	char ch = (char)va_arg(c, int);

	_write(ch);
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
		_write(str[i]);
	}
	return (i);
}

/**
 * print_int - prints an integer
 * @i: integer to print
 * Return: number of digits printed and if negative adds the sign '-'
 */
int print_int(va_list intg)
{
	int arr[10]; /* array of length 10 */
	int i, m, n, sum, j;

	n = va_arg(intg, int);
	j = 0; /* Counter */
	m = 1000000000; /* Maximum integer */
	arr[0] = n / m;

	for (i = 1; i < 10; i++) /* Loop to confirm not greater than maximum number */
	{
		m /= 10;
		arr[i] = (n / m) % 10;
	}

	if (n < 0) /* Check if number is negative sign it if negative */
	{
		_write('-');
		i++;
		for (i = 0; i < 10; i++)
			arr[i] *= -1;
	}

	for (i = 0, sum = 0; i < 10; i++) /* If not negative print value as is */
	{
		sum += arr[i];
		if (sum != 0 || i == 9)
		{
			_write('0' + arr[i]);
			j++;
		}
	}
	return (j);
}

/**
 * print_dcml - prints a decimal
 * @d: decimal to print
 * Return: number of digits printed and if negative sign number
 */
int print_dcml(va_list d)
{
	int arr[10]; /* array of length n */
	int i, m = 1000000000, dec, sum = 0, j = 0;


	dec = va_arg(d, int);

	arr[0] = dec / m;

	for (i = 1; i < 10; i++)
	{
		m /= 10;
		arr[i] = (dec / m) % 10;
	}

	if (dec < 0)
	{
		_write('-');
		j++;
		for (i = 0; i < 10; i++)
			arr[i] *= -1; /* Convert each number at position i to negative */
	}

	for (i = 0; i < 10; i++)
	{
		sum += arr[i];
		if (sum != 0 || i == 9)
		{
			_write('0' + arr[i]);
			j++;
		}
	}

	return (j);
}
