#include "../include/philosophers.h"

pthread_mutex_t	mutex;

int	check_available_fork(t_var *var, int *fork, int philosophers)
{
	if (fork[philosophers] && fork[(philosophers  + 1 ) % var->numberOfPhilosophers]
			&& var->sleep[philosophers] == FALSE)
	{
		fork[philosophers] = 0;
		fork[(philosophers + 1) % var->numberOfPhilosophers] = 0;
		return (SUCCESS);
	}
	return (FAIL);
}

void	get_starting_time(t_var *var)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	var->starting_time = start.tv_usec;
}

void	print_interval(t_var *var)
{
	struct timeval time;
	long 	interval;

	gettimeofday(&time, NULL);
	interval = time.tv_usec - var->starting_time;
	printf("%ld", interval / 1000);
}

void	*incremente(void *var)
{
	t_var *var2 = var;
	pthread_mutex_lock(&mutex);
	var2->numberOfForks++;
	printf("Fork number %d\n", var2->numberOfForks);
	pthread_mutex_unlock(&mutex);
	if (var2->numberOfForks >= 20)
		var2->loop = 0;
	return (NULL);
}

int	run_thread(t_var *var)
{
	int	i;

	while (var->loop) {
		i = -1;
		while (++i < var->numberOfPhilosophers && var->loop)
			pthread_mutex_init(&var->mutex[i], NULL);
		i = -1;
		while (++i < var->numberOfPhilosophers && var->loop) {
			if (pthread_create(&(var->philosophers)[i], NULL, (void *) incremente, (void *) var) != 0)
				return (error(PTHREAD_CREATE_ERROR));
		}
		i = -1;
		while (++i < var->numberOfPhilosophers && var->loop) {
			if (pthread_join(var->philosophers[i], NULL) != 0)
				return (error(PTHREAD_JOIN_ERROR));
		i = -1;
		while (++i < var->numberOfPhilosophers && var->loop)
			pthread_mutex_destroy(&var->mutex[i]);
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_var	var[1];

    if (check_input(argc, argv) == ERROR)
		return (ERROR);
	init_table(var, argv);
	var->numberOfForks = 0;
    return (run_thread(var));
}