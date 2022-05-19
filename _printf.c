#include "main.h"
#include <stdlib.h>

/**
 * check_specifiers - checks if there is a valid specifier
 * @format: format specifier
 * Return: pointer to valid function or NULL
 */
static int (*check_specifiers(const char *format))(va_list)
{
    unsigned int i;
    print_type p[] = {
        {"c", print_c},
        {"s", print_s},
        {NULL, NULL}
    }
    for (i=0; p[i].t != NULL; i++)
    {
        if (*(p[i].t) == *format)
        {
            break;
        }
    }
    return (p[i].f);
}

/**
 * _printf - prints whatever is passed into it
 * @format: list of types passed to the function
 * Return: characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, c = 0;
	va_list list;
	int (*f)(va_list);
	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			c++;
		}
		if (!format[i])
			return (c);
		f = check_specifiers(&format[i + 1]);
		if (f != NULL)
		{
			c += f(valist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		c++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(list);
	return (c);
}