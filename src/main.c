#include "philosophers.h"

_Bool	is_philo_dead(t_var *var, _Bool *philoDied)
{
	pthread_mutex_lock(&var->mutex_die);
	*philoDied = var->philoDied;
	pthread_mutex_unlock(&var->mutex_die);
	if (*philoDied == TRUE)
		return (TRUE);
	return (FALSE);
}

void	ft_sleep(int milliseconds, t_var *var)
{
	int		i;
	_Bool	philoDied;

	i = 100;
	pthread_mutex_lock(&var->mutex_die);
	philoDied = var->philoDied;
	pthread_mutex_unlock(&var->mutex_die);
	while (i < milliseconds && philoDied == FALSE)
	{
		pthread_mutex_lock(&var->mutex_die);
		philoDied = var->philoDied;
		pthread_mutex_unlock(&var->mutex_die);
		usleep(100 * 1000);
		i += 100;
	}
	if (philoDied == FALSE)
		usleep((milliseconds - (i - 100)) * 1000);
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

void
is_philo_alive(t_philosopher *philosopher, t_var *var, struct timeval timestamp, struct timeval end)
{
	pthread_mutex_lock(&var->mutex_die);
	if (var->philoDied == FALSE && elapsed_time(timestamp, end) > var->timeToDie)
	{
		philosopher->var->philoDied = TRUE;
		print_philo_died(philosopher);
	}
	pthread_mutex_unlock(&philosopher->var->mutex_die);
}

int	handle_philos_death(t_philosopher *philosopher)
{
	struct timeval	timestamp;
	struct timeval	end;
	_Bool 			philoDied;
	t_var			*var;

	var = philosopher->var;
	philoDied = FALSE;
	gettimeofday(&timestamp, NULL);
	while (philoDied == FALSE)
	{
		gettimeofday(&end, NULL);
		is_philo_dead(var, &philoDied);
		refresh_timestamp(philosopher, &timestamp);
		is_philo_alive(philosopher, var, timestamp, end);
	}
	return (SUCCESS);
}

int	sit_at_table(void *functionPhilosopher)
{
	t_philosopher	*philosopher = functionPhilosopher;
	t_var			*var = philosopher->var;
	_Bool 			philoDied;

	philoDied = FALSE;
	while (philoDied == FALSE && var->numberOfPhilosophers > 1)
	{
		if (is_philo_dead(var, &philoDied) == TRUE)
			break ;
		if (take_forks(var, philosopher) == MUTEX_LOCK_ERROR)
			return (ERROR);
		eat(var, philosopher);
		if (put_down_forks(var, philosopher) == MUTEX_UNLOCK_ERROR)
			return (ERROR);
		if (is_philo_dead(var, &philoDied) == TRUE)
			break ;
		go_sleep(var, philosopher);
		if (is_philo_dead(var, &philoDied) == TRUE)
			break ;
		is_thinking(var, philosopher);
		if (is_philo_dead(var, &philoDied) == TRUE)
			break ;
	}
	//unlock_all(var);
	return (SUCCESS);
}

int	run_thread(t_philosopher *philosophers, t_var *var)
{
	if (mutex_init(var->forks, var->numberOfPhilosophers) == MUTEX_INIT_ERROR)
		return (ERROR);
	if (mutex_init(&var->mutex_die, 1) == MUTEX_INIT_ERROR)
		return (ERROR);
	if (mutex_init(&var->mutex_print, 1) == MUTEX_INIT_ERROR)
		return (ERROR);
	get_starting_timestamp(var);
	if (thread_create_philosopher(philosophers) == PTHREAD_CREATE_ERROR)
		return (ERROR);
	if (thread_create_monitor(philosophers) == PTHREAD_CREATE_ERROR)
		return (ERROR);
	if (thread_join_philosopher(philosophers) == PTHREAD_JOIN_ERROR)
		return (ERROR);
	if (thread_join_monitor(philosophers) == PTHREAD_JOIN_ERROR)
		return (ERROR);
	if (mutex_destroy(var->forks, var->numberOfPhilosophers) == MUTEX_DESTROY_ERROR)
		return (ERROR);
	if (mutex_destroy(&var->mutex_die, 1) == MUTEX_DESTROY_ERROR)
		return (ERROR);
	if (mutex_destroy(&var->mutex_print, 1) == MUTEX_DESTROY_ERROR)
		return (ERROR);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_var	var[1];

    if (check_input(argc, argv) == ERROR)
		return (EXIT_FAILURE);
	if (init_table(var, argv) == ERROR)
		return (EXIT_FAILURE);
	if (run_thread(var->philosopher, var) == ERROR)
		return (EXIT_FAILURE);
	ft_free(var->philosopher);
	ft_free(var->forks);
    return (EXIT_SUCCESS);
}
