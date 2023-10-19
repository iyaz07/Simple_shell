#include"shell.h"
/**
 * _skip_delimiters - Helper function to skip delimiters.
 * @string: The string to process.
 * @delim: The delimiter characters.
 */
void _skip_delimiters(char **string, const char *delim)
{
	while (**string && strchr(delim, **string))
		(*string)++;
}
/**
 * _extract_token - Helper function to extract a token.
 * @string: The string to process.
 * @delim: The delimiter characters.
 * Return: A newly allocated token or NULL on failure.
 */
char *_extract_token(char **string, const char *delim)
{
	int i = 0;
	char *token;
	char *start = *string;

	while (**string && !strchr(delim, **string))
	{
		i++;
		(*string)++;
	}

	if (i == 0)
		return (NULL);

	token = malloc(sizeof(char) * (i + 1));

	strncpy(token, start, i);
	token[i] = '\0';

	return (token);
}
