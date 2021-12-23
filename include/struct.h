#ifndef PHILOSOPHERS_STRUCT_H
#define PHILOSOPHERS_STRUCT_H

#include <pthread.h>

typedef struct	s_var {
	int			numberOfPhilosophers;
	int 		numberOfForks;
	long int		timeToDie;
	int 		timeToEat;
	int		 	timeToSleep;
	int 		*forks;
	int 		*sleep;
	volatile int	loop;
	long 		starting_time;
	pthread_mutex_t *mutex;
	pthread_t	*philosophers;
}				t_var;

#endif
