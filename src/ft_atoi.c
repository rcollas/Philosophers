#include "utils.h"

static	int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static	int	ft_is_space(char c)
{
	if (c == '\f' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	nb;

	nb = 0;
	sign = 1;
	if (str_len(nptr) > 10)
		return (-1);
	while (ft_is_space(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		nb = nb * 10 + *nptr - 48;
		nptr++;
	}
	if (nb * sign > 2147483647)
		return (-1);
	else if (nb * sign < -2147483648)
		return (-1);
	return ((int)nb * sign);
}