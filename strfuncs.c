#include "shell.h"
/**
 * _strlen - Calculate the length of a string.
 *
 * @str: The input string.
 * Return: The length of the input string.
 */
int _strlen(const char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
/**
 * _strcmp - Compare two strings.
 *
 * @str1: The first input string.
 * @str2: The second input string.
 * Return: 0 if the strings are equal, a positive or negative value otherwise.
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while ((str1[i] != '\0') && (str2[i] != '\0') && (str1[i] == str2[i]))
	i++;

	if (str1[i] == '\0'  && str2[i] == '\0')
	{
	return (0);
	}

	else
	{
	return (1);
	}
}

/**
 * _strcpy - Copy a string.
 *
 * @dest: The destination string to copy to.
 * @src: The source string to copy from.
 * Return: The destination string after copying.
 */
char *_strcpy(char *dest, char *src)
{
	int len = 0;
	int i = 0;
	
	len = _strlen(src);

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
