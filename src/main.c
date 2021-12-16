#include "philosophers.h"

int	check_available_fork(t_var *var, int *fork, int philosophers)
{
	if (fork[philosophers] && fork[(philosophers  + 1 ) % var->numberOfPhilosophers]
			&& var->sleep[philosophers] == FALSE)
	{
		fork[philosophers] = 0;
		fork[(philosophers + 1) % var->numberOfPhilosophers] = 0;
		printf("Forks are available to philo %d\n\n", philosophers);
		return (SUCCESS);
	}
	return (FAIL);
}

void	print_timestamp(t_var *var)
{
	struct timeval	timestamp;
	long 			interval;

	gettimeofday(&timestamp, NULL);
	interval = (timestamp.tv_usec - var->time.tv_usec) / 1000;
	printf("%ld", interval);
}

void	get_timestamp(t_var *var)
{
	struct timeval start;
	gettimeofday(&start, NULL);
	var->time = start;
}

void	take_fork(void *functionVar)
{
	t_var	*var = functionVar;
	pthread_mutex_lock(&var->forks[var->num]);
	printf("num = %d\n", var->num);
	pthread_mutex_unlock(&var->forks[var->num]);
}

int	run_thread(t_var *var)
{
	if (mutex_init(var->forks, var->numberOfPhilosophers) == MUTEX_INIT_ERROR)
		return (ERROR);
	if (thread_create(var) == PTHREAD_CREATE_ERROR)
		return (ERROR);
	if (thread_join(var) == PTHREAD_JOIN_ERROR)
		return (ERROR);
	if (mutex_destroy(var->forks, var->numberOfPhilosophers) == MUTEX_DESTROY_ERROR)
		return (ERROR);
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	t_var	var[1];

    if (check_input(argc, argv) == ERROR)
		return (ERROR);
	init_table(var, argv);
	get_timestamp(var);
	if (run_thread(var) == ERROR)
		return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}