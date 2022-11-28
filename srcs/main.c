/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:33:36 by tlahin            #+#    #+#             */
/*   Updated: 2022/11/08 09:33:38 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			g_ant;
t_room_list	g_hashtable[HASH_SIZE];

int	main(int ac, char **av)
{

	if (av[0])
		ft_printf("\n");
	if (ac != 1)
		ft_printf("Input file error\n");
	else
	{
		init_global();
		read_map();
	}
	return (0);
}
