#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>

void promptt(void);
char    *ft_strdup(const char *s1);
void    *ft_memcpy(void *dst, const void *src, size_t n);
int ft_strlen(const char *str);
void    free_args(char **args);
int             ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, char *src);
char *path_find(char *command, char **env);
void ft_error(char *str, char *error, int i);
char	*ft_strcpy(char *dest, char *src);

#endif
