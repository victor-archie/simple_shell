#ifndef _SHELL_H
#define _SHELL_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define NOT_BUILTIN 67

/**
 * struct builtin- struct for built-in function
 * @name: name of the function
 * @action: what the function does
 */

typedef struct builtin
{
	char *name;
	int (*action)();
} builtin_action;

extern int errno;
extern char **environ;

void initialize_all_program_data(void);

void runner(char *prompt);
void tokenize(void);

char *_strtok(char *str, char *delim);
int execute_binary(void);
char *_getenv(const char *key);
int _strcmp(char *s1, char *s2);
int isatty(int fd);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
size_t _strlen(char *string);
int _atoi(char *s);
int is_builtin(void);

void print_error_message(void);

ssize_t _getline(void);

void free_pointers_array(char **arr);

extern int execution_counter;
extern char *cur_cmdline;
extern char **tokens;
extern char *program_name;

#endif
