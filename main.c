#include "main.h"
char **argv;
char *bufferDuplicate = NULL;
char *bufferCommand = NULL;
/**
 * main - A simple Shell Program
 * Return: 0 on Success, 1 on fail
 */

int main()
{
	char *token, *prompt = "";
	const char *delim = " \n";
	size_t no_Byte = 0;
	ssize_t no_Char;
	int num_token, counter, i, argc;

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		prompt = "($) ";	
	while (1)
	{
		write(STDIN_FILENO, prompt,strlen(prompt));
		no_Char = getline(&bufferCommand, &no_Byte, stdin);
		
		if (no_Char == -1)
		{
			return (-1);
		}
		bufferDuplicate = strdup(bufferCommand);
		token = strtok(bufferCommand, delim);
		for (num_token = 0; token != NULL; num_token++) /* Get Number of tokens to malloc argv*/
			token = strtok(NULL, delim);
		argv = malloc(sizeof(char *) * num_token);
		argc = num_token + 1;
		if (argv == NULL) /* Check if memory is allocated succesfully*/
		{
			printf("Argv memory allocation error.\n");
			free(bufferCommand);
			return (-1);
		}
		token = strtok(bufferDuplicate, delim);
		for (counter = 0; token != NULL; counter++) /* Copying tokens to argv variable */
		{
			argv[counter] = malloc(sizeof(char) * strlen(token + 1));
			strcpy(argv[counter], token);
			token = strtok(NULL, delim);
		}
		argv[counter] = NULL; /* Terminate the array with NULL*/
		if (strcmp(argv[0], "exit") == 0)
			exit_builtin();
		if (strcmp(argv[0], "env") == 0)
			environ_builtin();
		execCmd(argv); /*Execute the Command */
	}
	for (i = 0; i < argc; i++)
		free(argv[i]);
	free(bufferDuplicate);
	free(bufferCommand);
	free(argv);

	return (0);
}
