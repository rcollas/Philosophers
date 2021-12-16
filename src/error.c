#include "error.h"
#include "utils.h"

int	pthread_create_error(void)
{
	ft_putstr_fd("Thread creation failed\n", 2);
	return (-1);
}

int	pthread_join_error(void)
{
	ft_putstr_fd("Thread join failed\n", 2);
	return (-2);
}

int	mutex_init_error(void)
{
	ft_putstr_fd("Mutex init failed\n", 2);
	return (-3);
}

int mutex_destroy_error(void)
{
	ft_putstr_fd("Mutex destroy failed\n", 2);
	return (-4);
}

int	error(int errnum)
{
	if (errnum == PTHREAD_CREATE_ERROR)
		return (pthread_create_error());
	if (errnum == PTHREAD_JOIN_ERROR)
		return (pthread_join_error());
	if (errnum == MUTEX_INIT_ERROR)
		return (mutex_init_error());
	if (errnum == MUTEX_DESTROY_ERROR)
		return (mutex_destroy_error());
	return (0);
}