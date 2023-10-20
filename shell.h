#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#define INITIAL_BUFFER_SIZE 1024 
#define REALLOCATION_FACTOR 2
char **path_tokens();
char *checkpath(char **path, char **av);
char *_getenv(const char *variable_name);
extern char **environ;
char **tokens(char *buffer);
int _strlen(const char *str);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(const char *str);
void freemem(char **av);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void _printenv(void);
void execute_command(char *argument, char **av);
void process_input(char *buffer);
void shell_loop(void);
char *_strcat(char *dest, const char *src);
char *_strstr(const char *haystack, const char *needle);
void pathing_error(char **av);
ssize_t _getline(char **lineptr, size_t *n, int file_descriptor);
char *_strchr(char *str, int c);
int _fgetc(int file_descriptor);
char *realloc_buffer(char *buffer, size_t *n);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
char *_strtok(char *str, const char *delim);
void _skip_delimiters(char **string, const char *delim);
char *_extract_token(char **string, const char *delim);
#endif
