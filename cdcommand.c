#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int _changedirectory(char **av, char *input, int *exiti)
{	
	int stat;
    	char str[128];

    	(void)input;
    	(void)exiti;

    	if (av[1] == NULL || strcmp(av[1], "~") == 0)
        	stat = chdir(getenv("HOME"));
    	else if (strcmp(av[1], "-") == 0)
        	stat = chdir(getenv("OLDPWD"));
    	else
        	stat = chdir(av[1]);

    	if (stat == -1)
    	{
        	perror("cd");
        	return 0;
	}
	setenv("OLDPWD", getenv("PWD"), 1);
    	setenv("PWD", getcwd(str, sizeof(str)), 1);
    	return 1;
}
