#include "shell.h"

/**
 * _strcmp - compares two strings.
 *
 * @s1: first string that runs through the program.
 * @s2: second string that runs through the program.
 * Return: Always 0.
 */

int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i;

	if (s1 == NULL || s2 == NULL)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
* _strlen - returns the length of a string.
* @s: a pointer for the string
*
* Return: length of a string.
*/

int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * _strchr - locates a character in a string.
 *
 * @s: pointer to a string that runs in the function.
 * @c: character located in a string.
 * Return: a pointer to the first occurance of the character.
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (*s == c)
	{
		return (s);
	}
	return (NULL);
}

/**
 * _strcpy - copy a source input ont destinated input
 * @dest: target where will be stored the input
 * @src: source to copy from
 *
 *
 * Return: dest address
 * On error: -1 inapropiate entry
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; *(src + i) != '\0'; i++)
		*(dest + i) = *(src + i);

	*(dest + i) = *(src + i); /* adding '\0' character */

	return (dest);
}

/**
 * _strdup - function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter
 * @s: source to copy
 *
 *
 * Return: address where is stored the result
 * On error: -1 inapropiate entry
 */

char *_strdup(char *s)
{
	char *arr;

	if (!s)
		return (NULL);

	arr = malloc((_strlen(s) * sizeof(*arr)) + 1);

	if (!arr)
		return (NULL);

	_strcpy(arr, s);

	return (arr);
}
