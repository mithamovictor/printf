#include <unistd.h>

/**
 * _putchar - function that writes c to stdout
 * @c: character to be printed
 * Return: on success 1
 * On error, -1 is written and errno is apprpriately set
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
