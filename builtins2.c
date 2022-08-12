#include "shell.h"
/**
 * _env - prints the current environment
 * @data: struct of data
 * Return: Always 0.
 */
int _env(sh_t *data __attribute__((unused)))
{
	int i;

	if (!environ)
		return (FAIL);
	for (i = 0; data->env[i]; i++)
	{
		PRINT(data->env[i]);
		PRINT("\n");
	}
	(void)data->args;
	return (NEUTRAL);
}

/**
 * new_setenv - creates a new environment variable, or edits an existing
 environment.
 * @data: pointer to struct of variables
 *
 * Return: Always 0, on failure -1.
 */
int new_setenv(sh_t *data __attribute__((unused)))
{
	char **env_var = NULL, **new_environ, *new_value;
	size_t size;
	int index;

	if (data->args[1] == NULL || data->args[2] == NULL)
	{
		print_error2(data, "Incorrect number of arguments\n");
		return (FAIL);
	}
	new_value = malloc(_strlen(data->args[0]) + 1 + _strlen(data->args[1]) + 1);
	if (new_value == NULL)
	{
		print_error2(data, "Incorrect number of args\n");
		return (FAIL);
	}
	_strcpy(new_value, data->args[0]);
	_strcat(new_value, "=");
	_strcat(new_value, data->args[1]);

	env_var = _getenv2(data->args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_value;
		return (NEUTRAL);
	}
	for (size = 0; environ[size]; size++)
		;
	new_environ = malloc(sizeof(char *) * (size + 2));
	if (!new_environ)
	{
		free(new_value);
		print_error2(data, "Incorrect number of args\n");
	}
	for (index = 0; environ[index]; index++)
		new_environ[index] = environ[index];

	free(environ);
	environ = new_environ;
	environ[index] = new_value;
	environ[index + 1] = NULL;
	return (0);
}
/**
 * new_unsetenv - remove an environment variable
 * @data: pointer to a struct of variables
 *
 * Return: Always 0, -1 on failure.
 */

int new_unsetenv(sh_t *data __attribute__((unused)))
{
	char **env_var, **new_environ;
	size_t size;
	int index, index2;

	if (data->args[0] == NULL)
	{
		print_error2(data, ": Incorrect number of arguments\n");
		return (FAIL);
	}
	env_var = _getenv2(data->args[0]);
	if (env_var == NULL)
	{
		print_error2(data, ": No variable to unset");
		return (NEUTRAL);
	}
	for (size = 0; environ[size]; size++)
		;
	new_environ = malloc(sizeof(char *) * size);
	if (new_environ == NULL)
	{
		print_error2(data, NULL);
		abort_hsh(data);
	}
	for (index = 0, index2 = 0; environ[index]; index++)
	{
		if (*env_var == environ[index])
		{
			free(*env_var);
			continue;
		}
		new_environ[index2] = environ[index];
		index2++;
	}
	free(environ);
	environ = new_environ;
	environ[size - 1] = NULL;

	return (0);
}
