//header

#include "libft.h"

void	ft_arrdel(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i] != NULL)
		ft_strdel(&(*arr)[i++]);
	free(*arr);
	(*arr) = NULL;
}