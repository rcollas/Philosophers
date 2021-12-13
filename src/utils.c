#include "utils.h"

size_t	str_len(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *str, int fd)
{
	write (fd, str, str_len(str));
}

_Bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

_Bool	is_not_numeric(char *str)
{
	size_t	i;

	i = -1;
	while (is_digit(str[++i]))
	{
		if (str[i + 1] == '\0')
			return (FALSE);
	}
	return (TRUE);
}
