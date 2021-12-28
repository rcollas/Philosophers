#ifndef DO_ACTION_H
# define DO_ACTION_H

# include <pthread.h>
# include <sys/time.h>
# include "struct.h"
# include "error.h"
# include "utils.h"
# include "print_state.h"

# define EAT 3

int	put_down_forks(t_var *var, t_philosopher *philosopher);
int	eat(t_var *var, t_philosopher *philosopher);
int	go_sleep(t_var *var, t_philosopher *philosopher);
int	is_thinking(t_var *var, t_philosopher *philosopher);
int	take_forks(t_var *var, t_philosopher *philosopher);

#endif
