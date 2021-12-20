#include "../include/philosophers.h"

void	init_fork(int *tab, int size)
{
	int i;

	i = -1;
	if (!tab)
		return ;
	while (++i < size)
	{
		tab[i] = 1;
	}
}

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

void	init_table(t_var *var, char **argv)
{
	var->numberOfPhilosophers = atoi(argv[1]);
	var->philoDied = FALSE;
	var->numberOfForks = var->numberOfPhilosophers;
	var->timeToDie = atol(argv[2]);
	var->timeToEat = atoi(argv[3]);
	var->timeToSleep = atoi(argv[4]);
	var->forks = (pthread_mutex_t *)calloc(sizeof(pthread_mutex_t), var->numberOfForks);
	init_philosophers(var);
}
