#include  "shell.h"
/**
 * tokens - Tokenize a string based on spaces, newlines, or tabs.
 *
 * @buffer: The input string to be tokenized.
 * Return: An array of strings (tokens) obtained from the input.
 */
char **tokens(char *buffer)
{
	int i = 0;
	char *token = NULL;
	char **av = NULL;

	av = (char **)malloc(sizeof(char *) * 20);
	token = _strtok(buffer, " \n\t");

	while (token != NULL)
	{
		av[i] = (char *)malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(av[i], token);
		i++;
		token = _strtok(NULL, " \n\t");
	}

	av[i] = NULL;


	if (i == 0)
	{
		freemem(av);
		return (NULL);
	}

	return (av);
}

/**
 * path_tokens - Tokenize the PATH environment variable.
 *
 * Return: An array of strings representing directories in the PATH.
 */
char **path_tokens()
{
	int i = 0;
	char *token;
	char **av;
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);

	av = (char **)malloc(sizeof(char *) *  20);

	if (av == NULL)
	{
		free(path_copy);
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	token = _strtok(path_copy, ":");
	while (token != NULL)
	{
		av[i] = _strdup(token);
		token = _strtok(NULL, ":");
		i++;
	}
	av[i] = NULL;
	free(path_copy);
	return (av);
}
/**
 * _strtok - Custom string tokenizer function.
 *
 * @str: The string to tokenize. Pass the input string on the first call, and NULL
 *       on subsequent calls to continue tokenization.
 * @delim: A string containing delimiter characters used to separate tokens.
 *
 * Return: A pointer to the next token found in the input string or NULL
 *         if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
    static char *string;
    int i = 0;
    char *token;
    int n = 0;

    if (str != NULL)
    {
        string = str;
    }

    if (*string != '\0')
    {
        while (*string != '\0' && strchr(delim, *string) != NULL)
        {
            string++;
        }

        if (*string == '\0')
        {
            return (NULL);
        }

        while (*string != '\0' && strchr(delim, *string) == NULL)
        {
            i++;
            string++;
        }

        token = malloc(sizeof(char) * (i + 1));
        
	if (token == NULL)
        {
            return (NULL);
        }

        string -= i;

        for (n = 0; n < i; n++)
        {
            *(token + n) = *string;
            string++;
        }

        *(token + n) = '\0';

        if (*string != '\0')
        {
            string++;
        }

        return (token);
    }

    return (NULL);
}

