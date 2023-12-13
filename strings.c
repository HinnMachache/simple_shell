#include "main.h"
/**
 * _strncat - Concatenates strings 
 */
char *_strncat(char *dest, char *src, int n)
{
	int length = 0, i;

	for (i = 0; dest[i] != '\0'; i++) /*Get to end of dest string*/
	{
		length++;
	}
	for (i = 0; i < n && src[i] != '\0'; i++) /* concatenate src to dest*/
	{
		dest[length + i] = src[i];
	}
	dest[length + i] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares Srings
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 - *s2 != 0)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}
