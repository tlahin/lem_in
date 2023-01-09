/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:53:18 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:53:20 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_que(t_que *q, t_link *start)
{
	q->que[0] = start;
	q->remaining = 1;
	q->count = 1;
	q->index = 0;
}

void	init_path(int *r_index, int *backward_link_used, t_room **old)
{
	*r_index = 0;
	*backward_link_used = 0;
	*old = NULL;
}

void	init_globals(int *path_found, t_flags *flags)
{
	g_crossed = 1;
	g_table->ants = 0;
	g_table->start = NULL;
	g_table->end = NULL;
	g_optimal_path_count = 0;
	g_optimal_line_count = 0;
	*path_found = 0;
	g_map = (char *)ft_memalloc(sizeof(char) * STRING_SIZE);
	check_malloc((void *)g_map);
	flags->no_distr = 0;
	flags->line = 0;
	flags->no_map = 0;
}

void	init_ant_movement(t_ant_distr *distr)
{
	distr->str_size = STRING_SIZE;
	distr->line = (char *)ft_memalloc(sizeof(char) * distr->str_size);
	check_malloc(distr->line);
}
