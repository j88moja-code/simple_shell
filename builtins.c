#include "shell.h"

#define SETOWD(V) (V = _strdup(_getenv("OLDPWD")))
/**
 * change_dir - changes directory
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number will returned
 */
int change_dir(sh_t *data)
{
	char *home;

	home = _getenv("HOME");
	if (data->args[1] == NULL)
	{
		SETOWD(data->oldpwd);
		if (chdir(home) < 0)
			return (FAIL);
		return (SUCCESS);
	}
	if (_strcmp(data->args[1], "-") == 0)
	{
		if (data->oldpwd == 0)
		{
			SETOWD(data->oldpwd);
			if (chdir(home) < 0)
				return (FAIL);
		}
		else
		{
			SETOWD(data->oldpwd);
			if (chdir(data->oldpwd) < 0)
				return (FAIL);
		}
	}
	else
	{
		SETOWD(data->oldpwd);
		if (chdir(data->args[1]) < 0)
			return (FAIL);
	}
	return (SUCCESS);
}
#undef GETCWD
/**
 * abort_hsh - exit the program
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number will returned
 */
int abort_hsh(sh_t *data __attribute__((unused)))
{
	int i, len_of_int = 10;
	unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (data->args[0])
	{
		if (data->args[0][0] == '+')
		{
			i = 1;
			len_of_int++;
		}
		for (; data->args[0][i]; i++)
		{
			if (i <= len_of_int && data->args[0][i] >= '0' && data->args[0][i] <= '9')
			{
				num = (num * 10) + (data->args[0][i] - '0');
			}
			else
			{
				data->error_msg = _strdup("Illegal number\n");
				return (FAIL);
			}
		}
	}
	else
	{
		return (-3);
	}
	if (num > max - 1)
	{
		data->error_msg = _strdup("Illegal number\n");
		return (FAIL);
	}
	free_data(data);
	free(data->args);
	free_env();
	exit(num);
}
/**
 * display_help - display the help menu
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number will returned
 */
int display_help(sh_t *data)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(data->args[1], O_RDONLY);
	if (fd < 0)
	{
		data->error_msg = _strdup("no help topics match\n");
		return (FAIL);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			data->error_msg = _strdup("cannot write: permission denied\n");
			return (FAIL);
		}
	}
	PRINT("\n");
	return (SUCCESS);
}
/**
 * handle_builtin - handle and manage the builtins cmd
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 * ------- (Fail) negative number will returned
 */
int handle_builtin(sh_t *data)
{
	blt_t blt[] = {
		{"exit", abort_hsh},
		{"cd", change_dir},
		{"env", _env},
		{"setenv", new_setenv},
		{"unsetenv", new_unsetenv},
		{"help", display_help},
		{NULL, NULL}
	};
	int i = 0;

	while ((blt + i)->cmd)
	{
		if (_strcmp(data->args[0], (blt + i)->cmd) == 0)
			return ((blt + i)->f(data));
		i++;
	}
	return (FAIL);
}
