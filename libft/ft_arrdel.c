/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:14:13 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/09 17:14:14 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
