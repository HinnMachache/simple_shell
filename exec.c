#include "main.h"
/**
 * execCmd - executes command
 */
 

void execCmd(char **argv)
{
	char *command = NULL, *actualCommand = NULL;
	int status;
	pid_t pid;
	
	if(argv)
	{
		command = argv[0];
		actualCommand = command_Location(command);
		
		if (actualCommand && access(actualCommand, X_OK) == 0)
		{
			pid = fork();
			
			if (pid < 0)
			{
				free(bufferDuplicate);
				free(argv);
				free(actualCommand);
				perror("Error");
				exit(1);
			}
			else if (pid == 0)
			{
				if (execve(actualCommand, argv, NULL) == -1)
				{
					perror("Error");
					exit(1);
				}
				free(argv);
				free(bufferDuplicate);
				free(actualCommand);
			}
			else
			{
				waitpid(pid, &status, 0);
				free(argv);
				free(bufferDuplicate);
				free(actualCommand);
			}
		}
		else
		{
			free(argv);
			free(bufferDuplicate);
			free(actualCommand);
			perror("./hsh");
		}
	}
}
