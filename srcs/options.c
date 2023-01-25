/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:36:25 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 15:36:26 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	print_help(void)
{
	ft_printf("\nUSAGE\n\n");
	ft_printf("\t./lem-in [-h] [-l] [-q] [-nm] [-nd] < 'map'\n\n");
	ft_printf("OPTIONS\n\n");
	ft_printf("\t-h\t\tPrints the synopsis and a list of commands\n\n");
	ft_printf("\t-l\t\tPrints the ant movement line count\n\n");
	ft_printf("\t-nm\t\tDisable printing the map\n\n");
	ft_printf("\t-nd\t\tDisable printing the ant movement\n\n");
	ft_printf("\t-q\t\tEnables silent mode to not print map nor ant movement\n\n");
	free(g_map);
	exit (0);
}

void	now_handle_it(t_flags *flags)
{
	if (flags->no_map == 0)
		ft_printf("%s\n", g_map);
	if (flags->line == 1)
		ft_printf("%d\n", g_optimal_line_count);
	if (g_table->start_end_connected == 1)
		special_move();
	else if (flags->no_distr == 0)
		ant_movement();
}

void	options(int ac, char **av, t_flags *flags)
{
	int	i;

	i = 0;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (ft_strcmp(av[i], "-l") == 0)
				flags->line = 1;
			else if (ft_strcmp(av[i], "-q") == 0)
			{
				flags->no_map = 1;
				flags->no_distr = 1;
			}
			else if (ft_strcmp(av[i], "-nd") == 0)
				flags->no_distr = 1;
			else if (ft_strcmp(av[i], "-nm") == 0)
				flags->no_map = 1;
			if (ft_strcmp(av[i], "-h") == 0)
				print_help();
			i++;
		}
	}
}
