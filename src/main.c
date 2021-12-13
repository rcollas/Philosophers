#include "../include/philosophers.h"

pthread_mutex_t	mutex;

int	check_available_fork(t_var *var, int *fork, int philosophers)
{
	if (fork[philosophers] && fork[(philosophers  + 1 ) % var->numberOfPhilosophers]
			&& var->sleep[philosophers] == FALSE)
	{
		fork[philosophers] = 0;
		fork[philosophers + 1] = 0;
		return (SUCCESS);
	}
	return (FAIL);
}

void	*incremente(void *var)
{
	t_var *functionVar = (t_var *)var;

	pthread_mutex_lock(&mutex);
		//printf("seconds = %ld, micro seconds = %ld\n", time.tv_sec, time.tv_usec);
		if (check_available_fork(functionVar, functionVar->forks, functionVar->numberOfForks) == SUCCESS)
		{
			printf("Philosophers %d is eating\n", functionVar->numberOfForks);
			printf("Fork %d is used\n", functionVar->numberOfForks /*% (functionVar->numberOfPhilosophers - 1)*/);
			printf("Fork %d is used\n", (functionVar->numberOfForks + 1) % (functionVar->numberOfPhilosophers));
			functionVar->sleep[functionVar->numberOfForks] = TRUE;
		}
		functionVar->numberOfForks++;
		/*
		gettimeofday(&start, NULL);
		usleep(var->timeToEat);
		usleep(var->timeToSleep);
		gettimeofday(&end, NULL);
		printf("time = %ld\n", end.tv_usec - start.tv_usec);
		printf("time to die = %ld\n", var->timeToDie);
		//if (end.tv_usec - start.tv_usec > var->timeToDie)
		//	exit (1);
		 */
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	run_thread(t_var *var)
{
	int	i;

	i = -1;
	pthread_mutex_init(&mutex, NULL);
	while (++i < var->numberOfPhilosophers)
	{
		if (pthread_create(&(var->philosophers)[i], NULL, (void *) incremente, (void *) var) != 0)
			return (error(PTHREAD_CREATE_ERROR));
	}
	i = -1;
	while (++i < var->numberOfPhilosophers)
	{
		if (pthread_join(var->philosophers[i], NULL) != 0)
			return (error(PTHREAD_JOIN_ERROR));
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}

int main(int argc, char **argv)
{
	t_var	var[1];

    if (check_input(argc, argv) == ERROR)
		return (ERROR);
	init_table(var, argv);
	var->numberOfForks = 0;
	printf("1st iter\n");
	run_thread(var);
	init_fork(var->forks, var->numberOfPhilosophers);
	var->numberOfForks = 0;
	printf("2nd iter\n");
	run_thread(var);
	init_fork(var->forks, var->numberOfPhilosophers);
	var->numberOfForks = 0;
	printf("last iter\n");
    return (run_thread(var));
}