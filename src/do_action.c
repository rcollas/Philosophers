#include "do_action.h"

int	put_down_forks(t_var *var, t_philosopher *philosopher)
{
	if (philosopher->id % 2 == 0)
	{
		if (pthread_mutex_unlock(&var->forks[philosopher->left_fork]) != 0)
			error(MUTEX_UNLOCK_ERROR);
		if (pthread_mutex_unlock(&var->forks[philosopher->right_fork]) != 0)
			error(MUTEX_UNLOCK_ERROR);
	}
	else
	{
		if (pthread_mutex_unlock(&var->forks[philosopher->right_fork]) != 0)
			error(MUTEX_UNLOCK_ERROR);
		if (pthread_mutex_unlock(&var->forks[philosopher->left_fork]) != 0)
			error(MUTEX_UNLOCK_ERROR);
	}
	return (SUCCESS);
}

int	eat(t_var *var, t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->var->mutex_die);
	philosopher->state = EAT;
	if (philosopher->max_meal)
		philosopher->meal_count++;
	pthread_mutex_unlock(&philosopher->var->mutex_die);
	print_philo_eating(philosopher);
	ft_sleep(var->time_to_eat, var);
	return (SUCCESS);
}

int	go_sleep(t_var *var, t_philosopher *philosopher)
{
	print_philo_sleeping(philosopher);
	ft_sleep(var->time_to_sleep, var);
	return (SUCCESS);
}

int	is_thinking(t_philosopher *philosopher)
{
	print_philo_thinking(philosopher);
	return (SUCCESS);
}

int	take_forks(t_var *var, t_philosopher *philosopher)
{
	if (philosopher->id % 2 != 0)
	{
		usleep(10);
		if (pthread_mutex_lock(&var->forks[philosopher->left_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
		if (pthread_mutex_lock(&var->forks[philosopher->right_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
	}
	else
	{
		if (pthread_mutex_lock(&var->forks[philosopher->right_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
		if (pthread_mutex_lock(&var->forks[philosopher->left_fork]) != 0)
			error(MUTEX_LOCK_ERROR);
	}
	print_philo_takes_fork(philosopher);
	return (SUCCESS);
}
