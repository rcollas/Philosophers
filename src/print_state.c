#include "philosophers.h"

void	print_philo_eating(t_philosopher *philosopher)
{
	printf("%ld", get_timestamp(philosopher->var->start));
	printf("ms : Philo %d is eating with forks %d and %d\n", philosopher->id + 1, philosopher->leftFork + 1, philosopher->rightFork + 1);
}

void	print_philo_sleeping(t_philosopher *philosopher)
{
	printf("%ld", get_timestamp(philosopher->var->start));
	printf("ms : Philo %d is sleeping\n", philosopher->id + 1);
}

void	print_philo_thinking(t_philosopher *philosopher)
{
	printf("%ld", get_timestamp(philosopher->var->start));
	printf("ms : Philo %d is thinking\n", philosopher->id + 1);
}

void	print_philo_died(t_philosopher *philosopher)
{
	printf("%ld", get_timestamp(philosopher->var->start));
	printf("ms : Philo %d died\n", philosopher->id + 1);
}
