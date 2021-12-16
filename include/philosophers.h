#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include "error.h"
#include "struct.h"
#include "utils.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1
# define ERROR 1
# define AVAILABLE 1


void	init_table(t_var *var, char **argv);
void	init_fork(int *tab, int size);
size_t	str_len(char *str);
int		check_args_numbers(int argc);
int		check_args_type(char **argv);
int		check_input(int argc, char **argv);
int		thread_create(t_var *var);
int		thread_join(t_var *var);
int		mutex_init(pthread_mutex_t *mutex, int size);
int		mutex_destroy(pthread_mutex_t *mutex, int size);
void	take_fork(void *functionVar);

#endif