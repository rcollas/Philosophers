#include "is_philo_dead.h"

_Bool	is_philo_dead(t_var *var, _Bool *philo_died)
{
	pthread_mutex_lock(&var->mutex_die);
	*philo_died = var->philo_died;
	pthread_mutex_unlock(&var->mutex_die);
	if (*philo_died == TRUE)
		return (TRUE);
	return (FALSE);
}

void	refresh_timestamp(t_philosopher *philosopher, struct timeval *timestamp)
{
	pthread_mutex_lock(&philosopher->var->mutex_die);
	if (philosopher->state == EAT)
	{
		gettimeofday(timestamp, NULL);
		philosopher->state = FULL;
	}
	pthread_mutex_unlock(&philosopher->var->mutex_die);
}

void	is_philo_alive(t_philosopher *philosopher, t_var *var,
		struct timeval timestamp, struct timeval end)
{
	pthread_mutex_lock(&var->mutex_die);
	if (var->philo_died == FALSE
		&& elapsed_time(timestamp, end) > var->time_to_die)
	{
		philosopher->var->philo_died = TRUE;
		print_philo_died(philosopher);
	}
	pthread_mutex_unlock(&philosopher->var->mutex_die);
}

int	handle_philos_death(t_philosopher *philosopher)
{
	struct timeval	timestamp;
	struct timeval	end;
	_Bool			philo_died;
	t_var			*var;

	var = philosopher->var;
	philo_died = FALSE;
	gettimeofday(&timestamp, NULL);
	while (philo_died == FALSE)
	{
		gettimeofday(&end, NULL);
		is_philo_dead(var, &philo_died);
		refresh_timestamp(philosopher, &timestamp);
		is_philo_alive(philosopher, var, timestamp, end);
	}
	return (SUCCESS);
}