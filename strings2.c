#include "shell.h"

/**
  * _strncmp - compares two strings.
  * @s1: pointer to the first string
  * @s2: pointer to the second string.
  * @n: number of bytes of the string to compare.
  * Return: < 0 if s1 is shorter than s2,
  *	0 for match
  *	> 0 if s1 is longer than s2.
  */

int _strncmp(const char *s1, const char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s[2] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-8);
}

