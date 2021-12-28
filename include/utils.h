#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <sys/time.h>
# include "struct.h"

# define TRUE 1
# define FALSE 0
# define ERROR 1
# define SUCCESS 0

_Bool	is_digit(char c);
_Bool	is_not_numeric(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_sleep(int milliseconds, t_var *var);

#endif
