#include "shell.h"
/**
 * _strdup - duplicates a string
 *
 * @str: string to be duplicated
 *
 * Return: pointer to str [head of new string]
 *
 */
char *_strdup(const char *str)
{
	char *newstr = NULL;
	size_t len = 0;

	len = _strlen(str);
	newstr = malloc(sizeof(char) * (len + 1));

	if (newstr == NULL)
		return (NULL);

	_memcpy(newstr, str, len);
	return (newstr);
}
/**
 * _strcat - concatenate strings
 *
 * @dest: A pointer to the destination string
 * @src: A pointer to the source string
 *
 * Return: value of dest
 *
 */
char *_strcat(char *dest, const char *src)
{
	int i = 0;
	int j = 0;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _strstr - Find the first occurrence of a substring in a string.
 * @haystack: The input string to search.
 * @needle: The substring to search for in @haystack.
 *
 * Return: A pointer to the beginning of the located substring, or NULL if the
 *         substring is not found.
 */
char *_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack != '\0')
	{
		const char *h = haystack;
		const char *n = needle;

		while (*n != '\0' && *h == *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
