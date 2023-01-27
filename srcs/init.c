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

void	init_variables(t_lem_in *lem_in, int *path_found, t_flags *flags)
{
	lem_in->crossed = 1;
	lem_in->table->ants = 0;
	lem_in->table->start = NULL;
	lem_in->table->end = NULL;
	lem_in->optimal_path_count = 0;
	lem_in->optimal_line_count = 0;
	*path_found = 0;
	lem_in->map = (char *)ft_memalloc(sizeof(char) * STRING_SIZE);
	check_malloc((void *)lem_in->map, lem_in);
	flags->no_distr = 0;
	flags->line = 0;
	flags->no_map = 0;
	lem_in->table->start_end_connected = 0;
}

void	init_ant_movement(t_ant_distr *distr, t_lem_in *lem_in)
{
	distr->str_size = STRING_SIZE;
	distr->line = (char *)ft_memalloc(sizeof(char) * distr->str_size);
	check_malloc(distr->line, lem_in);
}
