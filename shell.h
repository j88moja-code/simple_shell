#ifndef SHELL_H
#define SHELL_H
/**
 * Libraries used by the project.
 */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>

/* Global constants */
#define TOKEN_BUFFER_SIZE 64
#define LINE_SIZE 1024

/**
 * Environment variables
 */
extern char **environ;

/**
 * The built ins
 */
int checker(char **cmd, char *buffer);
void prompt(void); /*Prompts for input*/
void *_getline(void); /*Input*/
char *str_path(char **path, char *args);/*Tests the path command*/
char *get_path(char **path, char *args);
int handle_builtin(char **args, char *line);
void exit_shell(char **arg, char *line); /*Exit the evironment*/
void env_shell(char **args, char *line); /*Get the environment*/

/**
 * The stings that will be entered into the environment
 */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
void execution(char *cp, char **cmd);
char *find_path(void);

#endif /* SHELL_H */
