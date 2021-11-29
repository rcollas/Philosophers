#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#define TRUE 1
#define FALSE 0
#define ERROR 1

typedef struct	s_var {
	int			numberOfPhilosophers;
	int 		numberOfForks;
	long int		timeToDie;
	int 		timeToEat;
	int		 	timeToSleep;
	pthread_t	*philosophers;
}				t_var;

size_t	str_len(char *str);
void	put_str_fd(char *str, int fd);
void	init_table(t_var *var, char **argv);
_Bool	is_digit(char c);
_Bool	is_not_numeric(char *str);
int		check_args_numbers(int argc);
int		check_args_type(char **argv);
int		check_input(int argc, char **argv);

#endif