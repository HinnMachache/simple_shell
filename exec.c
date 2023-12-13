#include "main.h"
/**
 * execCmd - executes command
 */
 

int execCmd(char **argv)
{
	char *command = NULL, *actualCommand = NULL;
	int status;
	pid_t pid;
	
	if(argv)
	{
		command = argv[0];
		actualCommand = command_Location(command);
		
		if (_strcmp(argv[0], "exit") == 0)
                        exit_builtin(argv[1]);
                if (_strcmp(argv[0], "env") == 0)
		{
                        environ_builtin();
			return(0);
		}		
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
	return (0);
}
