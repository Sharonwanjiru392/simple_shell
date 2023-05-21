#include "shell.h"

/**
 * _eputs - Prints an input string to the standard output
 * @str: The string to be printed
 *
 * Return: None
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Writes the character 'c' to the standard error stream
 * @c: The character to be printed
 *
 * Return: On success, 1.
 * On error, -1 is returned, and 'errno' is set appropriately.
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - Writes the character 'c' to the given file descriptor 'fd'
 * @c: The character to be written
 * @fd: The file descriptor to write to
 *
 * Return: On success, 1.
 * On error, -1 is returned, and 'errno' is set appropriately.
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - Prints the input string 'str' to specified file descriptor 'fd'
 * @str: The string to be printed
 * @fd: The file descriptor to write to
 *
 * Return: The number of characters written.
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

