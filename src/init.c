#include "philosophers.h"

int	init_philosophers(t_var *var)
{
	t_philosopher	*philosopher;
	int				i;

	i = -1;
	philosopher = (t_philosopher *)calloc(sizeof(t_philosopher),
			var->number_of_philosophers);
	if (!philosopher)
		return (error(CALLOC_ERROR));
	while (++i < var->number_of_philosophers)
	{
		philosopher[i].var = var;
		philosopher[i].id = i;
		philosopher[i].right_fork = i;
		philosopher[i].left_fork = (i + 1) % var->number_of_philosophers;
		philosopher[i].state = STARVING;
	}
	var->philosopher = philosopher;
	return (SUCCESS);
}

int	init_table(t_var *var, char **argv)
{
	var->number_of_philosophers = atoi(argv[1]);
	var->philo_died = FALSE;
	var->number_of_forks = var->number_of_philosophers;
	var->time_to_die = atol(argv[2]);
	var->time_to_eat = atoi(argv[3]);
	var->time_to_sleep = atoi(argv[4]);
	var->forks = (pthread_mutex_t *)calloc(sizeof(pthread_mutex_t),
			var->number_of_forks);
	if (!var->forks)
		return (error(CALLOC_ERROR));
	if (init_philosophers(var) == CALLOC_ERROR)
		return (CALLOC_ERROR);
	return (SUCCESS);
}
