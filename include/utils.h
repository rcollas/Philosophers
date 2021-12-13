#ifndef PHILOSOPHERS_UTILS_H
#define PHILOSOPHERS_UTILS_H

#include <unistd.h>

# define TRUE 1
# define FALSE 0
# define ERROR 1
# define SUCCESS 0

_Bool	is_digit(char c);
_Bool	is_not_numeric(char *str);
void	ft_putstr_fd(char *str, int fd);

#endif
