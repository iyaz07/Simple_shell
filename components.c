#include "shell.h"
/**
 * shell_loop - Main loop of the simple shell program.
 *
 * This function represents the main loop of the shell program. It handles
 * reading user input, processing it, and executing the appropriate commands.
 */
void shell_loop(void)
{
	char *buffer = NULL;
	size_t char_read = 0;
	size_t len;

	while (1)
	{
		int interactive = isatty(STDIN_FILENO);

		if (interactive != 0)
			write(1, "$ ", 2);
		if (getline(&buffer, &char_read, stdin) == -1)
		{
			break;
			perror("./hsh");
			exit(1);
		}
		len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';
		if (len == 1 && buffer[0] == '\0')
		{
			buffer = NULL;
			continue;
		}
		process_input(buffer);

		if (interactive == 0)
			break;
	}
}
/**
 * process_input - Processes user input in the shell.
 *
 * This function processes the user input by tokenizing it, determining the
 * command to execute, and taking appropriate actions based on the command.
 *
 * @buffer: The input string from the user.
 */
void process_input(char *buffer)
{
	char **av = tokens(buffer);
	char **path;
	char *argument;
	
	if (av != NULL)
	{
		if (_strcmp(av[0], "env") == 0)
		{
			freemem(av);
			_printenv();
		}
		else if (_strcmp(av[0], "exit") == 0)
		{
			free(buffer);
			freemem(av);
			exit(0);
		}
		else
		{
			path = path_tokens();
			argument = checkpath(path, av);

			if (argument != NULL)
			{
			execute_command(argument, av);
			}
		}
	}
}
