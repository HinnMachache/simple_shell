#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void execCmd(char **);
char *command_Location(char *);
void exit_builtin(void);
int _changedirectory(char **av, char *input, int *exiti);
int comments();

#endif
