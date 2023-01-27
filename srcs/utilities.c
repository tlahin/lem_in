/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:53:58 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:54:00 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Creates a new 'link' element to the list of links
** in a room
*/

t_link	*add_link(t_room *from_room, t_room *to_room, t_lem_in *lem_in)
{
	t_link	*link;

	link = (t_link *)ft_memalloc(sizeof(t_link));
	check_malloc((void *)link, lem_in);
	set_link(link, from_room, to_room, 0);
	link->next = from_room->link;
	from_room->link = link;
	return (link);
}

void	set_link(t_link *link, t_room *from, t_room *to, int flow)
{
	link->from = from;
	link->to = to;
	link->flow = flow;
	link->crossed = 0;
}

void	set_tracker(t_tracker *tracker, int index, int steps)
{
	tracker->index = index;
	tracker->steps = steps;
}

void	free_and_exit(t_lem_in *lem_in)
{
	free_everything(lem_in);
	exit(0);
}

void	set_special_path(t_path **path, t_lem_in *lem_in)
{
	path[0] = (t_path *)ft_memalloc(sizeof(t_path));
	check_malloc((void *)path[0], lem_in);
	path[0]->ant_count = lem_in->table->ants;
	path[0]->total_steps = 1;
	path[0]->rooms
		= (t_room **)
		ft_memalloc(sizeof(t_room *) * path[0]->total_steps);
	check_malloc((void *)path[0], lem_in);
	path[0]->rooms[0] = lem_in->table->start->link->to;
	path[1] = NULL;
}
