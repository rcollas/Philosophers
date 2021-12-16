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

void	init_table(t_var *var, char **argv)
{
	var->numberOfPhilosophers = atoi(argv[1]);
	var->num = 0;
	var->lock = 1;
	var->numberOfForks = var->numberOfPhilosophers;
	var->timeToDie = atol(argv[2]);
	var->timeToEat = atoi(argv[3]);
	var->timeToSleep = atoi(argv[4]);
	var->philosophers = (pthread_t *)calloc(sizeof(pthread_t),
			var->numberOfPhilosophers + 1);
	var->forks = (pthread_mutex_t *)calloc(sizeof(pthread_mutex_t), var->numberOfForks);
	var->sleep = (int *)calloc(sizeof(int), var->numberOfPhilosophers);
	var->has_eat = (int *)calloc(sizeof(int), var->numberOfPhilosophers);
}
