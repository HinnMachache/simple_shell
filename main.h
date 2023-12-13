#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>

/* Global Variables */
extern char *bufferCommand;
extern char **argv;
extern char *bufferDuplicate;

/* Function Prototype */
void execCmd(char **);
char *command_Location(char *);
void exit_builtin(void);
<<<<<<< HEAD
int _changedirectory(char **av, char *input, int *exiti);
int comments();

extern char **environ;

=======
void environ_builtin(void);
>>>>>>> fac2e41596f9cb32452dfa6e2822bfbe20f4a29f

#endif
