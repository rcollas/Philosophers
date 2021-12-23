#include "philosophers.h"

int	mutex_init(pthread_mutex_t *mutex, int size)
{
	int i;

	i = -1;
	while (++i < size)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
			return (error(MUTEX_INIT_ERROR));
	}
	return (SUCCESS);
}

int	mutex_destroy(pthread_mutex_t *mutex, int size)
{
	int i;

	i = -1;
	while (++i < size)
	{
		if (pthread_mutex_destroy(&mutex[i]) != 0)
			return (error(MUTEX_DESTROY_ERROR));
	}
	return (SUCCESS);
}
