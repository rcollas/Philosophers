#include "philosophers.h"

int	thread_create(t_philosopher *philosophers)
{
	int i;

	i = -1;
	while (++i < philosophers->var->numberOfPhilosophers)
	{
		if (pthread_create(&(philosophers[i]).philosopher, NULL, (void *) sit_at_table, (void *) &philosophers[i]) != 0)
			return (error(PTHREAD_CREATE_ERROR));
	}
	return (SUCCESS);
}

int	thread_join(t_philosopher *philosophers)
{
	int i;

	i = -1;
	while (++i < philosophers->var->numberOfPhilosophers)
	{
		if (pthread_join(philosophers[i].philosopher, NULL) != 0)
			return (error(PTHREAD_JOIN_ERROR));
	}
	return (SUCCESS);
}
