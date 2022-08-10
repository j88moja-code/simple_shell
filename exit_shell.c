#include "shell.h"

/**
 * exit_shell - Runs the builtin exit
 * @line: Line buffer of the user's input
 * @arg: Argument
 * 
 * Return: Void
 */
void exit_shell(char **arg, char *line)
{
    free(arg);
    free(line);
    exit(0);
}
