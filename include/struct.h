#ifndef PHILOSOPHERS_STRUCT_H
#define PHILOSOPHERS_STRUCT_H

#include <pthread.h>

typedef struct	s_var {
	int				numberOfPhilosophers;
	int 			numberOfForks;
	long int		timeToDie;
	int		 		timeToEat;
	int			 	timeToSleep;
	int 			philoDied;
	struct timeval	start;
	struct s_philosopher *philosopher;
	pthread_mutex_t	*forks;
}				t_var;

typedef struct s_philosopher {
	int			id;
	int 		rightFork;
	int 		leftFork;
	int			state;
	pthread_t 	philosopher;
	t_var		*var;
	struct timeval lastMeal;
}				t_philosopher;

#endif
