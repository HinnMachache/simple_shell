#include "main.h"
char *bufferDuplicate = NULL;
char **argv;
char *bufferCommand = NULL;
/**
 * main - A simple Shell Program
 * Return: 0 on Success, 1 on fail
 */

int main()
{
	char *token;
	char prompt[4] = "";
	const char *delim = " \n";
	size_t no_Byte = 0;
	ssize_t no_Char;
	int num_token, counter, i, argc;
	
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
   		 strcpy(prompt, "$ ");
   		 prompt[strlen(prompt)] = '\0';
	}

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		no_Char = getline(&bufferCommand, &no_Byte, stdin);
		
		if (no_Char == -1)
		{
			return (-1);
		}
		bufferDuplicate = strdup(bufferCommand);
		token = strtok(bufferCommand, delim);
		for (num_token = 0; token != NULL; num_token++) /* Get Number of tokens to malloc argv*/
			token = strtok(NULL, delim);
		num_token++;
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
			argv[counter] = malloc(sizeof(char) * strlen(token) + 1);
			strcpy(argv[counter], token);
			token = strtok(NULL, delim);
		}
		counter++;
		argv[counter] = NULL; /* Terminate the array with NULL*/
		execCmd(argv); /*Execute the Command */
	}
	for (i = 0; i < argc; i++)
		free(argv[i]);
	free(bufferDuplicate);
	free(bufferCommand);
	free(argv);

	return (0);
}
