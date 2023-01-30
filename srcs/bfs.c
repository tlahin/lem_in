/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:52:02 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:52:04 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	check_backward_usage(t_lem_in *lem_in, int flow)
{
	if (flow == BACKWARD)
		lem_in->backwards_link_used = BACKWARD;
}

static int	fewer_step_path(t_link *link, int new_steps, t_room **old_room)
{
	int	old_steps;

	old_steps = link->to->steps;
	if (new_steps >= old_steps)
		return (NOT_FOUND);
	*old_room = link->from;
	return (FOUND);
}

/*
** After bfs finds a connection to the end room
** Track the path backwards and check for already existing flows
*/
static int	conclude_path(t_link **que, t_tracker *tracker, \
	int q_i, t_lem_in *lem_in)
{
	int		r_i;
	int		target_index;
	t_link	r_que[SIZE];
	t_room	*old_room;

	init_path(&r_i, &old_room, lem_in);
	set_link(&r_que[r_i++], que[q_i]->to, que[q_i]->from, que[q_i]->flow);
	target_index = tracker[q_i].index;
	while (q_i > 0)
	{
		if (q_i == target_index)
		{
			if (que[q_i]->to->prev == que[q_i]->from
				&& fewer_step_path
				(que[q_i], tracker[q_i].steps, &old_room) == NOT_FOUND)
				return (NOT_FOUND);
			set_link(&r_que[r_i], que[q_i]->to, que[q_i]->from, que[q_i]->flow);
			check_backward_usage(lem_in, r_que[r_i++].flow);
			target_index = tracker[q_i].index;
		}
		q_i--;
	}
	return (augment(r_que, r_i, old_room, lem_in));
}

/*
** Create a que to arrange a search on the links
** using a 'breadth first search'
** Looks through the map
** for a connection to the 'end' room
** Will find the shortest connection, IF one exists
*/
int	bfs(t_link *start, t_lem_in *lem_in)
{
	t_que		q;
	int			result;
	t_tracker	tracker[SIZE];

	init_que(&q, start);
	tracker[0].steps = 0;
	result = 0;
	while (q.remaining--)
	{
		if (q.que[q.index]->crossed != lem_in->crossed)
		{
			if (q.que[q.index]->to != lem_in->table->end)
				q.remaining += search(q.que, &q.count, q.index, tracker);
			else
			{
				result = conclude_path(q.que, tracker, q.index, lem_in);
				if (result != NOT_FOUND)
					break ;
			}
			q.que[q.index]->crossed = lem_in->crossed;
		}
		q.index++;
	}
	lem_in->crossed++;
	return (result);
}
