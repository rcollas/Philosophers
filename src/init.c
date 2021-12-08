#include "../include/philosophers.h"

void	init_table(t_var *var, char **argv)
{
	var->numberOfPhilosophers = atoi(argv[1]);
	var->numberOfForks = var->numberOfPhilosophers;
	var->timeToDie = atol(argv[2]);
	var->timeToEat = atoi(argv[3]);
	var->timeToSleep = atoi(argv[4]);
	var->philosophers = (pthread_t *)calloc(sizeof(pthread_t),
			var->numberOfPhilosophers + 1);
}
