#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct printer - structure used for printing various printf specifiers
 * @t: format type to be printed
 * @fn: function used for printing
 */

typedef struct printer
{
	char *t;
    int (*fn)(va_list);
} printer_t;

int _write(char c);
int _printf(const char *format, ...);
int print_char(va_list c);
int print_str(va_list s);
int print_int(va_list intg);
int print_dcml(va_list d);

#endif
