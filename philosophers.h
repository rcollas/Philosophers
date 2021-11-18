#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#define TRUE 1
#define FALSE 0
#define ERROR 1

size_t  strLen(char *str);
void putStrFd(char *str, int fd);
_Bool isDigit(char c);
_Bool isNotNumeric(char *str);
int checkArgsNumbers(int argc);
int checkArgsType(char **argv);
int checkInput(int argc, char **argv);

#endif