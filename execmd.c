#include "shell.h"
/**
 * execute_command - Forks and executes a command in a child process.
 *
 * This function forks a child process and executes a command with the given
 * arguments using execve. It also waits for the child process to complete.
 *
 * @argument: The full path to the command to be executed.
 * @av: An array of strings representing the command and its arguments.
 */
void execute_command(char *argument, char **av)
{
	int status;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: ");
		freemem(av);
		exit(1);
	}

	if (child_pid == 0)
	{
		if (execve(argument, av, environ) == -1)
		{
			perror("./hsh");	
		}
		freemem(av);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
	}
}
