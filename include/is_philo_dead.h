#ifndef IS_PHILO_DEAD_H
# define IS_PHILO_DEAD_H

# include <sys/time.h>
# include "struct.h"
# include "timestamp.h"
# include "print_state.h"

# define TRUE 1
# define FALSE 0
# define EAT 3
# define FULL 0
# define SUCCESS 0
# define FAIL 1

_Bool	is_philo_dead(t_var *var, _Bool *philo_died);
void	refresh_timestamp(t_philosopher *philosopher,
			struct timeval *timestamp);
void	is_philo_alive(t_philosopher *philosopher, t_var *var,
			struct timeval timestamp, struct timeval end);
int		handle_philos_death(t_philosopher *philosopher);

#endif
