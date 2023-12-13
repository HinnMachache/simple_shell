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
int execCmd(char **);
char *command_Location(char *);
void exit_builtin(char *);
int _changedirectory(char **av, char *input, int *exiti);
int comments();
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);

extern char **environ;

void environ_builtin(void);

#endif
