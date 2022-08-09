#include "shell.h"
/**
 * is_path_form - chekc if the given fikenname is a path
 * @data: the data strucct pointer
 *
 * Return: (Success)
 * ------- (Fail) otherwise
 */
int is_path_form(sh_t *data)
{
	if (_strchr(data->args[0], '/') != 0)
	{
		data->cmd = _strdup(data->args[0]);
		return (SUCCESS);
	}
	return (FAIL);
}
