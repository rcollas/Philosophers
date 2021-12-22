#include "philosophers.h"



int	is_philo_died(t_philosopher *philosopher)
{
	struct timeval	timestamp;
	struct timeval	end;
	_Bool 			philo_died;

	philo_died = FALSE;
	gettimeofday(&timestamp, NULL);
	while (philo_died == FALSE)
	{
		pthread_mutex_lock(&philosopher->var->mutex_die);
		philo_died = philosopher->var->philoDied;
		pthread_mutex_unlock(&philosopher->var->mutex_die);
		pthread_mutex_lock(&philosopher->var->mutex_die);
		if (philosopher->state == EAT)
		{
			gettimeofday(&timestamp, NULL);
			philosopher->state = FULL;
		}
		pthread_mutex_unlock(&philosopher->var->mutex_die);
		gettimeofday(&end, NULL);
		pthread_mutex_lock(&philosopher->var->mutex_die);
		if (philosopher->var->philoDied == FALSE && elapsed_time(timestamp, end) > philosopher->var->timeToDie)
		{
			philosopher->var->philoDied = TRUE;
			print_philo_died(philosopher);
		}
		pthread_mutex_unlock(&philosopher->var->mutex_die);
	}
	return (SUCCESS);
}

int	sit_at_table(void *functionPhilosopher)
{
	t_philosopher	*philosopher = functionPhilosopher;
	t_var			*var = philosopher->var;
	_Bool 			philo_died;

	philo_died = FALSE;
	while (philo_died == FALSE)
	{
		pthread_mutex_lock(&var->mutex_die);
		philo_died = var->philoDied;
		pthread_mutex_unlock(&var->mutex_die);
		if (philo_died == TRUE)
			break ;
		take_forks(var, philosopher);
		eat(var, philosopher);
		put_down_forks(var, philosopher);
		pthread_mutex_lock(&var->mutex_die);
		philo_died = var->philoDied;
		pthread_mutex_unlock(&var->mutex_die);
		if (philo_died == TRUE)
			break ;
		go_sleep(var, philosopher);
		pthread_mutex_lock(&var->mutex_die);
		philo_died = var->philoDied;
		pthread_mutex_unlock(&var->mutex_die);
		if (philo_died == TRUE)
			break ;
		is_thinking(var, philosopher);
		pthread_mutex_lock(&var->mutex_die);
		philo_died = var->philoDied;
		pthread_mutex_unlock(&var->mutex_die);
		if (philo_died == TRUE)
			break ;
	}
	return (SUCCESS);
}

int	run_thread(t_philosopher *philosophers, t_var *var)
{
	if (mutex_init(var->forks, var->numberOfPhilosophers) == MUTEX_INIT_ERROR)
		return (ERROR);
	pthread_mutex_init(&var->mutex_die, NULL);
	pthread_mutex_init(&var->mutex_print, NULL);
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
	pthread_mutex_destroy(&var->mutex_die);
	pthread_mutex_destroy(&var->mutex_print);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_var	var[1];

    if (check_input(argc, argv) == ERROR)
		return (ERROR);
	init_table(var, argv);
	if (run_thread(var->philosopher, var) == ERROR)
		return (EXIT_FAILURE);
	ft_free(var->philosopher);
	ft_free(var->forks);
    return (EXIT_SUCCESS);
}
