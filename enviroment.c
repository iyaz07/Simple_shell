#include "shell.h"
/**
 * _getenv - Extract the value of an environment variable.
 *
 * @variable_name: The name of the environment variable.
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *variable_name)
{
	int i = 0;
	int var_len = _strlen(variable_name);

	while (environ[i] != NULL)
	{
		char *value = _strstr(environ[i], variable_name);

		if (value != NULL && value == environ[i])
		{
			if (value[var_len] == '=')
			{
				return (&value[var_len + 1]);
			}
		}
		i++;
	}
	return (NULL);
}
/**
 * _printenv - Print the environment variables.
 * Prints all the environment variables to the standard output.
 */
void _printenv(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}
/**
 * checkpath - Check if a command exists in the given paths.
 *
 * @path: An array of strings representing directories to search in.
 * @av: An array of strings representing the command and its arguments.
 * Return: The full path to the command if found, null otherwise.
 */
char *checkpath(char **path, char **av)
{
	int i = 0;

	if (access(av[0], F_OK) == 0)
	{
		return (av[0]);
	}
	while (path[i]  != NULL)

	{
		char *s = malloc(_strlen(path[i] + _strlen(av[0]) + 2));

		if (s == NULL)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		_strcpy(s, path[i]);  /*copythe path*/
		_strcat(s, "/");
		_strcat(s, av[0]);
		if (access(s, F_OK) == 0)
		{
			free(path[i]);
			return (s);
		}
		free(s);
		i++;
	}
	perror("./hsh");
	freemem(path);
	return (NULL);
}
