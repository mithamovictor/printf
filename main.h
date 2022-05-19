#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

int _write(char c);

/**
 * struct print - Check flags that need to be activated
 * @tp: the type to be printed
 * @fn: the function to print
 */

typedef struct print
{
	char *tp;
	int (*fn)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list, valist);
int print_s(va_list, valist);
int print_per(__attribute__((unused))va_list valist);
int print_i(va_list, valist);


#endif
