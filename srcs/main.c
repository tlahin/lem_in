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

int	main(int ac, char **av)
{
	t_parser	parser;
	t_link		start_link;
	int			path;

	if (av[0])
		ft_printf("\n");
	if (ac != 1)
		ft_printf("Input file error\n");
	else
	{
		parse_map(&parser);
		set_link(&start_link, g_table->start, g_table->start, 0);
		while (bfs(&start_link))
		{
			//find_path();
			path = 1;
		}
		g_table->start->ant = parser.ants;
		//check_special_path(path);
		free_everything();
	}
	return (0);
}
