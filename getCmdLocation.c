#include "main.h"
/**
 *
 */
char *command_Location(char *command)
{
	char *command_path, *command_path_Copy, *file_path, *token;
	int directory_len, command_len;
	struct stat bufferStat;

	command_path = getenv("PATH");

	if (command_path)
	{
		command_path_Copy = strdup(command_path);
		command_len = strlen(command);
		token = strtok(command_path_Copy, ":");
		
		while (token != NULL)
		{
			directory_len = strlen(token);
			file_path = malloc(sizeof(char *) * (command_len + directory_len + 2));
			strcpy(file_path, token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			
			if (stat(file_path, &bufferStat) == 0)
			{
				free(command_path_Copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				token = strtok(NULL, ":");
			}
		}
		free(command_path_Copy);

		if (stat(command, &bufferStat) == 0)
			return (command);

		return (NULL);
	}
	return (NULL);
}
