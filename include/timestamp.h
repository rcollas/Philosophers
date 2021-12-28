#ifndef TIMESTAMP_H
# define TIMESTAMP_H

# include <sys/time.h>
# include "error.h"
# include "struct.h"

long	get_timestamp(struct timeval start);
void	get_starting_timestamp(t_var *var);
long	elapsed_time(struct timeval start, struct timeval end);

#endif
