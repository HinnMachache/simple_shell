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

<<<<<<< HEAD
while (*env_when)
{
	write(STDIN_FILENO, *env_when, strlen(*env_when));
	env_when++;
}
}

void helpCommand() {
    printf("Simple Shell Help:\n");
    printf("  help - Display this help message\n");
    printf("  cd   - Change the current directory\n");
    printf("  exit - Exit the shell\n");
=======
	while (*env_when)
	{
		write(STDIN_FILENO, *env_when, strlen(*env_when));
		env_when++;
	}
>>>>>>> fac2e41596f9cb32452dfa6e2822bfbe20f4a29f
}
