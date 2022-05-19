#include <unistd.h>

/**
 *_write - writes character to stdout
 *@c: char
 *Return: 0 or 1
 */

int _write(char c)
{
	return (write(1, &c, 1));
}
