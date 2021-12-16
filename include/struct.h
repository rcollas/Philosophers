#ifndef PHILOSOPHERS_STRUCT_H
#define PHILOSOPHERS_STRUCT_H

#include <pthread.h>

typedef struct	s_var {
	int				numberOfPhilosophers;
	int				num;
	int		 		i;
	int 			numberOfForks;
	long int		timeToDie;
	int		 		timeToEat;
	int			 	timeToSleep;
	int 			*sleep;
	int 			*has_eat;
	int				lock;
	struct timeval	time;
	pthread_t		*philosophers;
	pthread_mutex_t	*forks;
}				t_var;

#endif
