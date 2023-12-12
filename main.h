#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Global Variables */
extern char *bufferCommand;
extern char **argv;
extern char *bufferDuplicate;

/* Function Prototype */
void execCmd(char **);
char *command_Location(char *);
void exit_builtin(void);
void environ_builtin(void);

#endif
