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

int	mutex_lock_error(void)
{
	ft_putstr_fd("Mutex lock failed\n", 2);
	return (-5);
}

int	mutex_unlock_error(void)
{
	ft_putstr_fd("Mutex unlock failed\n", 2);
	return (-6);
}

int	calloc_error(void)
{
	ft_putstr_fd("Calloc failed\n", 2);
	return (-7);
}

int	gettimeofday_error(void)
{
	ft_putstr_fd("Gettimeofday failed\n", 2);
	return (-8);
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
	if (errnum == MUTEX_LOCK_ERROR)
		return (mutex_lock_error());
	if (errnum == MUTEX_UNLOCK_ERROR)
		return (mutex_unlock_error());
	if (errnum == CALLOC_ERROR)
		return (calloc_error());
	if (errnum == GETTIMEOFDAY_ERROR)
		return (gettimeofday_error());
	return (0);
}