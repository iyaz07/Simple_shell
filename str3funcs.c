#include "shell.h"
/**
 * _fgetc - Read a character from a file descriptor.
 *
 * @file_descriptor: The file descriptor to read from.
 *
 * Return: On success, returns the next character read as an integer.
 * if eof is reached, it returns EOF. On error, it returns EOF and sets the
 * appropriate error code.
 */
int _fgetc(int file_descriptor)
{
	char c;
	int bytes_read;

	file_descriptor = 0;
	bytes_read = read(file_descriptor, &c, 1);

	if (bytes_read == 1)
	{
		return ((int)c);
	}
	else
	{
		return (EOF);
	}
}
/**
 * _strtok - Custom string tokenizer function.
 *
 * @str: The string to tokenize. Pass the input string on the first call, NULL
 *      on subsequent calls to continue tokenization.
 * @delim: A string containing delimiter characters used to separate tokens.
 *
 * Return: A pointer to the next token found in the input string or NULL
 *      if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	static char *string;
	char *token;

	if (str != NULL)
		string = str;


	_skip_delimiters(&string, delim);

	if (*string == '\0')
		return (NULL);

	token = _extract_token(&string, delim);

	if (*string != '\0')
		string++;

	return (token);
}
