#include "../include/philosophers.h"

pthread_mutex_t	mutex;
int	i;
t_var	var[1];

void	*incremente()
{
	struct timeval start, end;

	if (var->numberOfForks >= 2) {
		var->numberOfForks -= 2;
		//printf("seconds = %ld, micro seconds = %ld\n", time.tv_sec, time.tv_usec);
		printf("Is eating\n");
		gettimeofday(&start, NULL);
		usleep(var->timeToEat);
		var->numberOfForks += 2;
		usleep(var->timeToSleep);
		gettimeofday(&end, NULL);
		printf("time = %ld\n", end.tv_usec - start.tv_usec);
		printf("time to die = %ld\n", var->timeToDie);
		if (end.tv_usec - start.tv_usec > var->timeToDie)
			exit (1);
	}
	else
		pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int main(int argc, char **argv)
{
	i = -1;
    if (check_input(argc, argv) == ERROR)
		return (ERROR);
	init_table(var, argv);
	pthread_mutex_init(&mutex, NULL);
	while (1) {
		for (int k = 0; k <= var->numberOfPhilosophers; k++)
			pthread_create(&(var->philosophers)[k], NULL, &incremente, NULL);
		for (int j = 0; j <= var->numberOfPhilosophers; ++j)
			pthread_join(var->philosophers[j], NULL);
	}
	pthread_mutex_destroy(&mutex);
    return (0);
}