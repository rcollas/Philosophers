#include "philosophers.h"

void	print_philo_eating(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->var->mutex_print);
	printf("%ld", get_timestamp(philosopher->var->start));
	printf(" %d is eating\n", philosopher->id + 1);
	pthread_mutex_unlock(&philosopher->var->mutex_print);
}

void	print_philo_sleeping(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->var->mutex_print);
	printf("%ld", get_timestamp(philosopher->var->start));
	printf(" %d is sleeping\n", philosopher->id + 1);
	pthread_mutex_unlock(&philosopher->var->mutex_print);
}

void	print_philo_thinking(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->var->mutex_print);
	printf("%ld", get_timestamp(philosopher->var->start));
	printf(" %d is thinking\n", philosopher->id + 1);
	pthread_mutex_unlock(&philosopher->var->mutex_print);
}

void	print_philo_died(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->var->mutex_print);
	printf("%ld", get_timestamp(philosopher->var->start));
	printf(" %d died\n", philosopher->id + 1);
	pthread_mutex_unlock(&philosopher->var->mutex_print);
}

void	print_philo_takes_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->var->mutex_print);
	printf("%ld", get_timestamp(philosopher->var->start));
	printf(" %d has taken a fork\n", philosopher->id + 1);
	pthread_mutex_unlock(&philosopher->var->mutex_print);
}