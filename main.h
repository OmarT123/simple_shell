#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS 17 /*command + 16 arguments (MAX)*/

int execute(char*[]);

#endif
