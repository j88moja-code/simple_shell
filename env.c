#include "shell.h"
/**
 * env_shell - prints the shell environment
 * @args: Argument from line
 * @line: user input buffer
 * Return: 0
 */
void env_shell(char **args, char *line)
{
	int size, i = 0;
	char **env = environ;

	while (env[i] != NULL)
	{
		size = _strlen(env[i]);
		write(1, env[i], size);
		write(1, "\n", 1);
		i++;
	}
}
