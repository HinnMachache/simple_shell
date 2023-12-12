#include "main.h"

int comments()
{
	char user_input[1024];
    	char *command;

    	while (1)
	{
		fgets(user_input, sizeof(user_input), stdin);
        	user_input[strcspn(user_input, "\n")] = '\0';
        	command = strtok(user_input, "#");

        	if (command != NULL)
		{
			system(command);
		}
	}

    return 0;
}
