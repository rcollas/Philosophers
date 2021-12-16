#include "philosophers.h"

int	thread_create(t_var *var)
{
	int i;

	i = -1;
	while (++i < var->numberOfPhilosophers)
	{
		var->num = i;
		if (pthread_create(&(var->philosophers)[i], NULL, (void *) take_fork, (void *) var) != 0)
			return (error(PTHREAD_CREATE_ERROR));
	}
	return (SUCCESS);
}

int	thread_join(t_var *var)
{
	int i;

	i = -1;
	while (++i < var->numberOfPhilosophers)
	{
		if (pthread_join(var->philosophers[i], NULL) != 0)
			return (error(PTHREAD_JOIN_ERROR));
	}
	return (SUCCESS);
}
