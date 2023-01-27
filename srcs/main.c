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

/* t_table	g_table[HASH_SIZE];
int		g_crossed;
int		g_optimal_path_count;
int		g_optimal_line_count;
t_path	*g_paths[SIZE];
char	*g_map; */

int	main(int ac, char **av)
{
	t_link		start_link;
	int			path_found;
	t_flags		flags;
	t_lem_in	lem_in;

	init_variables(&lem_in, &path_found, &flags);
	options(ac, av, &flags, &lem_in);
	parse_map(&lem_in);
	set_link(&start_link, lem_in.table->start, lem_in.table->start, 0);
	while (bfs(&start_link, &lem_in) && lem_in.table->start_end_connected != 1)
	{
		pathfinder(&lem_in);
		path_found = 1;
	}
	lem_in.table->start->ant = lem_in.table->ants;
	if (lem_in.table->start_end_connected == 1)
	{
		lem_in.optimal_line_count = 1;
		path_found = 1;
	}
	check_path(path_found, &lem_in);
	now_handle_it(&flags, &lem_in);
	free_everything(&lem_in);
	return (0);
}
