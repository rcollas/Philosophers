#include "philosophers.h"

int	init_philosophers(t_var *var)
{
	t_philosopher	*philosopher;
	int 			i;

	i = -1;
	philosopher = (t_philosopher *)calloc(sizeof(t_philosopher), var->numberOfPhilosophers);
	if (!philosopher)
		return (error(CALLOC_ERROR));
	while (++i < var->numberOfPhilosophers)
	{
		philosopher[i].var = var;
		philosopher[i].id = i;
		philosopher[i].rightFork = i;
		philosopher[i].leftFork = (i + 1) % var->numberOfPhilosophers;
		philosopher[i].state = STARVING;
	}
	var->philosopher = philosopher;
	return (SUCCESS);
}

int init_table(t_var *var, char **argv)
{
	var->numberOfPhilosophers = atoi(argv[1]);
	var->philoDied = FALSE;
	var->numberOfForks = var->numberOfPhilosophers;
	var->timeToDie = atol(argv[2]);
	var->timeToEat = atoi(argv[3]);
	var->timeToSleep = atoi(argv[4]);
	var->forks = (pthread_mutex_t *)calloc(sizeof(pthread_mutex_t), var->numberOfForks);
	if (!var->forks)
		return (error(CALLOC_ERROR));
	if (init_philosophers(var) == CALLOC_ERROR)
		return (CALLOC_ERROR);
	return (SUCCESS);
}
