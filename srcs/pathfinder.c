/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:53:40 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:53:42 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	count_steps(t_room *room, t_lem_in *lem_in)
{
	int	i;

	i = 1;
	while (room != lem_in->table->end)
	{
		room->steps = i++;
		room = room->next;
	}
	return (i);
}

/*
** Counts the amout of lines/turns
** required to transfer all the ants across
** given the current path(s)
*/

static int	count_lines(t_path **path, int p_count, t_lem_in *lem_in)
{
	int	p_index;
	int	line;
	int	step;
	int	max_ants;

	p_index = 0;
	step = 0;
	line = path[0]->total_steps;
	max_ants = lem_in->table->ants;
	while (max_ants > 0)
	{
		if (step > p_index)
		{
			step = 0;
			line++;
		}
		while (p_index + 1 < p_count
			&& line >= path[p_index + 1]->total_steps && step == 0)
		p_index++;
		path[step]->ant_count++;
		step++;
		max_ants--;
	}
	return (line);
}

/*
** Saves the 'best' paths into lem_in struct
*/
static void	set_optimal_path(t_path **paths, int p_count, t_lem_in *lem_in)
{
	int		p_index;
	int		room_index;
	t_room	*room;

	p_index = 0;
	while (p_index < p_count)
	{
		lem_in->paths[p_index] = paths[p_index];
		room_index = 0;
		room = lem_in->paths[p_index]->rooms[room_index];
		while (room_index < lem_in->paths[p_index]->total_steps)
		{
			lem_in->paths[p_index]->rooms[room_index] = room;
			room_index++;
			room = room->next;
		}
		p_index++;
	}
}

/*
** Returns the amount of paths being used
*/
static int	set_paths(t_path **path, t_lem_in *lem_in)
{
	int		p_count;
	t_link	*tmp;

	p_count = 0;
	tmp = lem_in->table->start->link;
	while (tmp)
	{
		if (tmp->flow == 1)
		{
			path[p_count] = (t_path *)ft_memalloc(sizeof(t_path));
			check_malloc((void *)path[p_count], lem_in);
			path[p_count]->ant_count = 0;
			path[p_count]->total_steps = count_steps(tmp->to, lem_in);
			path[p_count]->rooms
				= (t_room **)
				ft_memalloc(sizeof(t_room *) * path[p_count]->total_steps);
			check_malloc((void *)path[p_count], lem_in);
			path[p_count]->rooms[0] = tmp->to;
			p_count++;
		}
		tmp = tmp->next;
	}
	path[p_count] = NULL;
	return (p_count);
}

/*
** Collects and sorts the paths to calculate the final line/turn count
*/
int	pathfinder(t_lem_in *lem_in)
{
	int		line_count;
	int		p_count;
	t_path	*paths[SIZE];

	if (lem_in->table->start_end_connected == 1)
	{
		lem_in->optimal_line_count = 1;
		set_special_path(paths, lem_in);
		return (1);
	}
	p_count = set_paths(paths, lem_in);
	sort_paths(paths, 0, p_count - 1);
	line_count = count_lines(paths, p_count, lem_in);
	if (line_count < lem_in->optimal_line_count \
		|| lem_in->optimal_line_count == 0)
	{
		if (lem_in->optimal_path_count != 0)
			free_path(lem_in->paths, lem_in->optimal_path_count);
		set_optimal_path(paths, p_count, lem_in);
		lem_in->optimal_line_count = line_count;
		lem_in->optimal_path_count = p_count;
	}
	else
		free_path(paths, p_count);
	return (line_count);
}
