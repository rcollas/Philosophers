#include "free.h"

void	ft_free(void *to_free)
{
	if (to_free)
	{
		free (to_free);
		to_free = NULL;
	}
}

void	free_int_tab(int **tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		free (tab[i]);
	}
}
