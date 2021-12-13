#include "../include/philosophers.h"

pthread_mutex_t	mutex;
int	i;
t_var	var[1];
int is_sleeping = 0;

void	*eat(void *l)
{
	struct timeval start, end;
	int k;
	k = *(int *)l;

	//printf("seconds = %ld, micro seconds = %ld\n", time.tv_sec, time.tv_usec);
	gettimeofday(&start, NULL);
	if (k % 2 == 0 && !is_sleeping) {
		pthread_mutex_lock(&mutex);
		usleep(5);
		printf("Philosophers %d is eating\n", k);
		usleep(var->timeToEat);
	}
	else {
		pthread_mutex_unlock(&mutex);
		printf("Philosophers %d is eating\n", k);
	}

	gettimeofday(&end, NULL);
	return (NULL);
}

int main(int argc, char **argv)
{
	i = -1;
	int	k;
    if (check_input(argc, argv) == ERROR)
		return (ERROR);
	init_table(var, argv);
	pthread_mutex_init(&mutex, NULL);
	//while (1) {
	k = 0;
	while (++k <= var->numberOfPhilosophers)
	{
		pthread_create(&(var->philosophers)[k], NULL, &eat, (void *) &k);
	}
	k = 0;
	while (++k <= var->numberOfPhilosophers) {
		pthread_join(var->philosophers[k], NULL);
	}
	//}
	pthread_mutex_destroy(&mutex);
    return (0);
}