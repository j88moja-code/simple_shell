#include "shell.h"
/**
 * find_path - finds the path in the global environment
 *
 * Return: NULL if not found or print the path if found
 */
char find_path(void)
{
	int i;
	char *env = environ, *path;

	while (*env)
	{
		if (_strncmp(*env, "PATH =", 5) == 0)
		{
			path = *env;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
