#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "error.h"
# include "struct.h"
# include "utils.h"
# include "free.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1
# define ERROR 1
# define AVAILABLE 1
# define EAT 3
# define SLEEPING 2
# define STARVING 1
# define FULL 0

int		init_table(t_var *var, char **argv);
size_t	str_len(char *str);
int		check_args_numbers(int argc);
int		check_args_type(char **argv);
int		check_input(int argc, char **argv);
int		thread_create_philosopher(t_philosopher *philosophers);
int		thread_create_monitor(t_philosopher *philosophers);
int		thread_join_philosopher(t_philosopher *philosophers);
int		thread_join_monitor(t_philosopher *philosophers);
int		mutex_init(pthread_mutex_t *mutex, int size);
int		mutex_destroy(pthread_mutex_t *mutex, int size);
int		sit_at_table(void *functionVar);
long	get_timestamp(struct timeval start);
void	get_starting_timestamp(t_var *var);
void	print_philo_eating(t_philosopher *philosopher);
void	print_philo_sleeping(t_philosopher *philosopher);
void	print_philo_thinking(t_philosopher *philosopher);
void	print_philo_died(t_philosopher *philosopher);
void	print_philo_takes_fork(t_philosopher *philosopher);
int		put_down_forks(t_var *var, t_philosopher *philosopher);
int		eat(t_var *var, t_philosopher *philosopher);
int		go_sleep(t_var *var, t_philosopher *philosopher);
int		is_thinking(t_var *var, t_philosopher *philosopher);
int		take_forks(t_var *var, t_philosopher *philosopher);
int		handle_philos_death(t_philosopher *philosopher);
long	elapsed_time(struct timeval start, struct timeval end);

#endif