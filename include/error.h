#ifndef ERROR_H
# define ERROR_H

# define TRUE 1
# define FALSE 0
# define ERROR 1
# define SUCCESS 0

# define PTHREAD_CREATE_ERROR -1
# define PTHREAD_JOIN_ERROR -2

int	error(int errnum);

#endif