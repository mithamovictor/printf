#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct print - Check flags that need to be activated
 * @tp: the type to be printed
 * @fn: the function to print
 */

typedef struct print
{
  char *t;
  int (*f)(va_list);
} print_type;

int _putchar(char c);
int _printf(const char *format, ...);

#endif
