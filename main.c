#include "main.h"
/**
 * main - A simple Shell Program
 * Return: 0 on Success, 1 on fail
 */

int main()
{
	char *token, *prompt = "";
	char *bufferCommand = NULL, *bufferDuplicate = NULL;
	char **argv;
	const char *delim = " \n";
	size_t no_Byte = 0;
	ssize_t no_Char;
	int num_token, counter;

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		prompt = "($) ";	
	while (1)
	{
		write(STDIN_FILENO, prompt,strlen(prompt));	
		no_Char = getline(&bufferCommand, &no_Byte, stdin);
		bufferDuplicate = strdup(bufferCommand);
		
		if (no_Char == -1)
                        return (-1);
		token = strtok(bufferCommand, delim);
		for (num_token = 0; token != NULL; num_token++) /* Get Number of tokens to malloc argv*/
		{
			token = strtok(NULL, delim);
		}
		argv = malloc(sizeof(char *) * num_token);
		if (argv == NULL) /* Check if memory is allocated succesfully*/
		{
			printf("Argv memory allocation error.\n");
			return (-1);
		}
		token = strtok(bufferDuplicate, delim);
		for (counter = 0; token != NULL; counter++) /* Copying tokens to argv variable */
		{
			argv[counter] = malloc(sizeof(char *) * strlen(token));
			strcpy(argv[counter], token);
			token = strtok(NULL, delim);
		}
		argv[counter] = NULL; /* Terminate the array with NULL*/
		if (strcmp(argv[0], "exit") == 0)
		{
			exit_builtin();
		}
		execCmd(argv); /*Execute the Command */
	}
  
	free(bufferCommand);
	free(bufferDuplicate);
	free(argv);

	return (0);
}
