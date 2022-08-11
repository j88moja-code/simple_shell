#include "shell.h"
/**
 * free_data - frees data
 * @data: the data structure
 *
 * Return: (Success) positive number
 * ------- (Fail) negative number
 */
int free_data(sh_t *data)
{
	free(data->line);
	data->line = NULL;
	free(data->args);
	data->args = NULL;
	free(data->cmd);
	data->cmd = NULL;
	free(data->error_msg);
	data->error_msg = NULL;
	return (0);
}

