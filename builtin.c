#include "main.h"

/**
 * exit_builtin - to exit the current environment
 *
 * Return: void
 */

void exit_builtin(void)
{
	free(bufferDuplicate);
	free(argv);
	free(bufferCommand);
	exit(0);
}

/**
 * environ_builtin - that prints the current environment;
 * @env_when: pointer to a pointer
 * Return: void
 */

void environ_builtin(void)
{
	extern char **environ;
	char **env_when = environ;

	while (*env_when)
	{
		write(STDIN_FILENO, *env_when, strlen(*env_when));
		env_when++;
	}
}
