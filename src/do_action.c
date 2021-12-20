#include "philosophers.h"

int put_down_forks(t_var *var, t_philosopher *philosopher)
{
	if (pthread_mutex_unlock(&var->forks[philosopher->rightFork]) != 0)
		return (error(MUTEX_UNLOCK_ERROR));
	if (pthread_mutex_unlock(&var->forks[philosopher->leftFork]) != 0)
		return (error(MUTEX_UNLOCK_ERROR));
	return (SUCCESS);
}

int	eat(t_var *var, t_philosopher *philosopher)
{
	philosopher->state = STARVING;
	print_philo_eating(philosopher);
	usleep(var->timeToEat * 1000);
	philosopher->state = SLEEPING;
	return (SUCCESS);
}

int	go_sleep(t_var *var, t_philosopher *philosopher)
{
	print_philo_sleeping(philosopher);
	usleep(var->timeToSleep * 1000);
	return (SUCCESS);
}


int	is_thinking(t_var *var, t_philosopher *philosopher)
{
	(void)var;
	print_philo_thinking(philosopher);
	while (philosopher[philosopher->id + 1].state ==  SLEEPING)
		usleep(1);
	return (SUCCESS);
}

int	take_forks(t_var *var, t_philosopher *philosopher)
{
	if (philosopher->id % 2 != 0)
		usleep(300);
	if (pthread_mutex_lock(&var->forks[philosopher->rightFork]) != 0)
		return (error(MUTEX_LOCK_ERROR));
	if (pthread_mutex_lock(&var->forks[philosopher->leftFork]) != 0)
		return (error(MUTEX_LOCK_ERROR));
	return (SUCCESS);
}
