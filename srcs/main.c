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

t_table		g_table[HASH_SIZE];
int			g_crossed;
int			g_optimal_path_count;
int			g_optimal_line_count;
t_path		*g_optimal_paths[MAGIC_NUMBER];
char		*g_map;

int	main(int ac, char **av)
{
	t_link		start_link;
	int			path_found;

	if (ac > 1 && av[1])
		ft_printf("Let's go!\n");
	init_globals(&path_found);
	parse_map();
	set_link(&start_link, g_table->start, g_table->start, 0);
	while (bfs(&start_link))
	{
		pathfinder();
		path_found = 1;
	}
	g_table->start->ant = g_table->ants;
	check_special_path(path_found);
	move_the_bois();
	free_everything();
	return (0);
}
