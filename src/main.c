#include "philosophers.h"

int	is_philo_died(t_var *var, t_philosopher *philosopher)
{
	//while (philosopher->state == STARVING)
	//{
		//printf("timestamp is : %ld\n", get_timestamp(philosopher->lastMeal));
		if (get_timestamp(philosopher->lastMeal) > var->timeToDie && var->philoDied == FALSE)
		{
			var->philoDied = TRUE;
			print_philo_died(philosopher);
		}
//	}
	return (SUCCESS);
}

int	sit_at_table(void *functionPhilosopher)
{
	t_philosopher	*philosopher = functionPhilosopher;
	t_var			*var = philosopher->var;

	while (var->philoDied == FALSE)
	{
		take_forks(var, philosopher);
		gettimeofday(&philosopher->lastMeal, NULL);
		eat(var, philosopher);
		put_down_forks(var, philosopher);
		is_philo_died(var, philosopher);
		go_sleep(var, philosopher);
		is_philo_died(var, philosopher);
		//is_thinking(var, philosopher);
	}
	return (SUCCESS);
}

int	run_thread(t_philosopher *philosophers, t_var *var)
{
	if (mutex_init(var->forks, var->numberOfPhilosophers) == MUTEX_INIT_ERROR)
		return (ERROR);
	get_starting_timestamp(var);
	//while (var->philoDied == FALSE)
	//{
		if (thread_create(philosophers) == PTHREAD_CREATE_ERROR)
			return (ERROR);
		if (thread_join(philosophers) == PTHREAD_JOIN_ERROR)
			return (ERROR);
	//}
	if (mutex_destroy(var->forks, var->numberOfPhilosophers) == MUTEX_DESTROY_ERROR)
		return (ERROR);
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
