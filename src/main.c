#include "philosophers.h"

int	sit_at_table(void *functionPhilosopher)
{
	t_philosopher	*philosopher;
	_Bool			philo_died;

	philo_died = FALSE;
	philosopher = functionPhilosopher;
	while (philo_died == FALSE && philosopher->var->number_of_philosophers > 1)
	{
		if (is_philo_dead(philosopher->var, &philo_died) == TRUE)
			break ;
		if (take_forks(philosopher->var, philosopher) == MUTEX_LOCK_ERROR)
			return (ERROR);
		eat(philosopher->var, philosopher);
		if (put_down_forks(philosopher->var, philosopher) == MUTEX_UNLOCK_ERROR)
			return (ERROR);
		if (is_philo_dead(philosopher->var, &philo_died) == TRUE)
			break ;
		go_sleep(philosopher->var, philosopher);
		if (is_philo_dead(philosopher->var, &philo_died) == TRUE)
			break ;
		is_thinking(philosopher->var, philosopher);
		if (is_philo_dead(philosopher->var, &philo_died) == TRUE)
			break ;
	}
	return (SUCCESS);
}

int	run_thread(t_philosopher *philosophers, t_var *var)
{
	if (mutex_init(var->forks, var->number_of_philosophers) == MUTEX_INIT_ERROR)
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
	if (mutex_destroy(var->forks, var->number_of_philosophers)
		== MUTEX_DESTROY_ERROR)
		return (ERROR);
	if (mutex_destroy(&var->mutex_die, 1) == MUTEX_DESTROY_ERROR)
		return (ERROR);
	if (mutex_destroy(&var->mutex_print, 1) == MUTEX_DESTROY_ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	main(int argc, char **argv)
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
