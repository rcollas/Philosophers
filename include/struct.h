#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef struct s_var {
	int						number_of_philosophers;
	int						number_of_forks;
	long int				time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						philo_died;
	struct timeval			start;
	struct s_philosopher	*philosopher;
	pthread_mutex_t			*forks;
	pthread_mutex_t			mutex_die;
	pthread_mutex_t			mutex_print;
}				t_var;

typedef struct s_philosopher {
	int			id;
	int			right_fork;
	int			left_fork;
	int			state;
	pthread_t	philosopher;
	pthread_t	monitor;
	t_var		*var;
}				t_philosopher;

#endif
