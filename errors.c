#include "shell.h"
/**
 * print_error - ptints error messages to standard error
 * @vars: pointer to struct of variables
 * @msg: messages to point
 *
 * Return: void
 */
void print_error2(sh_t *data, char *msg)
{
	char *count;
	
	_puts2(data->args[0]);
	_puts2(": ");
	count = _uitoa(data->count);
	_puts2(count);
	free(count);
	_puts(": ");
	_puts(data->args[0]);
	if (msg)
	{
		_puts2(msg);
	}else
		perror("");
}

/**
 * _puts2 - prints a string to standard error
 * @str: string to print
 *
 * Return: void
 */
void _puts2(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		exit(1);
	}
}
