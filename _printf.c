#include "main.h"

/**
 * format_specifier - function that checks for list of specifiers
 * @format: checks this string from input
 * Return: Null if failed to find right function type and
 * on success, a ptr to the function type
 */

static int(*format_specifier(const char *format))(va_list)
{
	unsigned int j;
	printer_t p[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_int},
		{"d", print_dcml},
		{NULL, NULL}
	};

	for (j = 0; p[j].t != NULL; j++)
	{
		if (*(p[j].t) == *format)
		{
			break;
		}
	}
	return (p[j].fn);
}

/**
 * _printf - cunstomized function that prints according to specific formats
 * @format: argument types inputted for output format
 * Return: number of characters printed upon success and -1 upon failure
 */
int _printf(const char *format, ...)
{
	/**
	 * we create two varuiables i & J
	 * i will be the iterator of format string
	 * j will be a counter fo the iterations
	 */
	unsigned int i = 0, j = 0;
	va_list valist;
	int (*fn)(va_list);

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_write(format[i]);
			j++;
		}
		if (!format[i])
			return (j);
		fn = format_specifier(&format[i + 1]);

		if (fn != NULL)
		{
			j += fn(valist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_write(format[i]);
		j++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(valist);
	return (j);
}

