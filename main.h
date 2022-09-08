#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdarg.h>

/*define main prototypes*/
int get_tokens(char *);
char **alloc(int);
char **tokenize(char **, char *);
void execute(char *, char **, char **);
void free_space(char **, char *);

/* define sting manipulating prototypes */
int _strlen(char *);
char *_strcpy(char *, char*);
int _print(char *, ...);
int _strcmp(char *, char *);

/* define built-ins prototypes */
void my_exit(char **, char *);
void my_env(char **);
int check_built(char *, char **, char **, char *);

#endif

