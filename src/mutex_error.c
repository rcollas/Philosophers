#include "error.h"
#include "utils.h"

int	mutex_init_error(void)
{
	ft_putstr_fd("Mutex init failed\n", 2);
	return (-3);
}

int	mutex_destroy_error(void)
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
