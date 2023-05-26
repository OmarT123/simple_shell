#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS 17 /*command + 16 arguments (MAX)*/

char *const envp[] = {
	"HOSTNAME=5d790082c8dd",
	"LANGUAGE=en_US:en",
	"PWD=/tmp/correction/9749264685589369598515372578856239685975_5/235/282160",
	"TZ=America/Los_Angeles",
	"HOME=/root",
	"LANG=en_US.UTF-8",
	"SHLVL=2",
	"LC_ALL=en_US.UTF-8",
	"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
	"OLDPWD=/_=/usr/bin/env",
	NULL
};

int execute(char*[]);

#endif
