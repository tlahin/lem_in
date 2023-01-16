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

static void	check_backward_usage(int *current_status, int flow)
{
	if (flow == BACKWARD)
		*current_status = BACKWARD;
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
**
*/

static int	conclude_path(t_link **que, t_tracker *tracker, int q_i)
{
	int		r_i;
	int		target_index;
	int		backward_link_used;
	t_link	r_que[MAGIC_NUMBER];
	t_room	*old_room;

	init_path(&r_i, &backward_link_used, &old_room);
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
			check_backward_usage(&backward_link_used, r_que[r_i++].flow);
			target_index = tracker[q_i].index;
		}
		q_i--;
	}
	return (augment(r_que, r_i, old_room, backward_link_used));
}

/*
** Create a que to arrange a search on the links
** using a 'breadth first search'
** Looks through the map
** for a connection to the 'end' room
*/

int	bfs(t_link *start)
{
	t_que		q;
	int			result;
	t_tracker	tracker[MAGIC_NUMBER];

	init_que(&q, start);
	tracker[0].steps = 0;
	result = 0;
	while (q.remaining--)
	{
		if (q.que[q.index]->crossed != g_crossed)
		{
			if (q.que[q.index]->to != g_table->end)
				q.remaining += search(q.que, &q.count, q.index, tracker);
			else
			{
				result = conclude_path(q.que, tracker, q.index);
				if (result != NOT_FOUND)
					break ;
			}
			q.que[q.index]->crossed = g_crossed;
		}
		q.index++;
	}
	g_crossed++;
	return (result);
}
