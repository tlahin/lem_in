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

t_table	g_table[HASH_SIZE];
int		g_crossed;

int	main(int ac, char **av)
{
	t_parser	parser;
	t_link		start_link;
	int			path_found;

	if (ac != 1 || av[1])
		ft_printf("Input file error\n");
	else
	{
		init_parser(&parser);
		parse_map(&parser);
		set_link(&start_link, g_table->start, g_table->start, 0);
		while (bfs(&start_link))
		{
			pathfinder();
			path_found = 1;
		}
		g_table->start->ant = parser.ants;
		check_special_path(path_found);
		free_everything();
	}
	return (0);
}
