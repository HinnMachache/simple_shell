#include "main.h"

/**
 * exit_builtin - to exit the current environment
 *
 * Return: void
 */
void exit_builtin(char *status)
{
	int stat = 0;

	if (status != NULL)
		stat = atoi(status);

	free(bufferDuplicate);
	free(argv);
	free(bufferCommand);
	exit(stat);
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
		write(STDOUT_FILENO, *env_when, strlen(*env_when));
		write(STDOUT_FILENO, "\n", 1);
		env_when++;
	}
}

void helpCommand() {
    printf("Simple Shell Help:\n");
    printf("  help - Display this help message\n");
    printf("  cd   - Change the current directory\n");
    printf("  exit - Exit the shell\n");
}
