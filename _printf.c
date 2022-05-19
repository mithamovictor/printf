#include "main.h"

/**
 *_printf- copy of printf function
 *@format: string containing characters
 *Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	va_list valist;
	int i;
	int j;

	va_start(valist, format);

	op_t ops[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_per},
		{"d", print_i},
		{"i", print_i}
	};

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; *ops[j].op != '\0'; j++)
			{
				if (format[i + 1] == *ops[j].op)
				{
					_write(ops[j].fn(valist));
				}
			}
		}
		else
		{
			_write(format[i]);
		}
	}

	return (0);
}
