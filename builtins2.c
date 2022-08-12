#include "shell.h"
/**
 * _env - prints the current environment
 * @data: struct of data
 * Return: Always 0.
 */
int _env(sht_t *data __attribute__((unused)))
{
	int i;

	if (!environ)
		return(FAIL);
	for (i = 0; data->env[i]; i++)
	{
		PRINT(data->env[i]);
		PRINT("\n");
	}
	(void)data->args;
	return (NEUTRAL);
}

/**
 * new_setenv - creates a new environment variable, or edits an existing environment.
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
		data->status = 2;
		return (FAIL);
	}
	new_value = malloc(_strlen(data->args[0]) + 1 + _strlen(data->arg[1]) + 1);
	if (new_value == NULL)
	{
		print_error2(data, "Incorrect number of args\n");
		data->status = 2;
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
	for (size = 0; environ[size]; size++);
	new_environ = malloc(sizeof(char *) * (size + 2));
	if (!new_environ)
	{
		free(new_value);
		print_error2(data, "Incorrect number of args\n");
	}
	for (index = 0, environ[index]; index++)
		new_environ[index] = environ[index];

	free(environ);
	environ = new_environ;
	environ[index] = new_value;
	environ[index + 1] = NULL;
	
	return (0);
}

