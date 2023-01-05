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

static int	conclude_path(t_link **que, t_tracker *tracker, int q_index)
{
	int		r_index;
	int		target_index;
	int		backward_edge_used;
	t_link	r_que[MAGIC_NUMBER];
	t_room	*old_long_room;

	init_path(&r_index, &backward_edge_used, &old_long_room);
	set_link(&r_que[r_index++], que[q_index]->to, que[q_index]->from, que[q_index]->flow);
	target_index = tracker[q_index].index;
	while (q_index > 0)
	{
		if (q_index == target_index)
		{
			if (que[q_index]->to->prev == que[q_index]->from
				&& fewer_step_path(que[q_index], tracker[q_index].steps, &old_long_room) == NOT_FOUND)
				return (NOT_FOUND);
			set_link(&r_que[r_index], que[q_index]->to, que[q_index]->from, que[q_index]->flow);
			check_backward_usage(&backward_edge_used, r_que[r_index++].flow);
			target_index = tracker[q_index].index;
		}
		q_index--;
	}
	return (augment(r_que, r_index, old_long_room, backward_edge_used));
}

int bfs(t_link *start)
{
	t_que		q;
	int			path;
	t_tracker	tracker[MAGIC_NUMBER];

	init_que(&q, start);
	tracker[0].steps = 0;
	path = 0;
	while (q.remaining--)
	{
		if (q.que[q.index]->crossed != g_crossed)
		{
			if (q.que[q.index]->to != g_table->end)
				q.remaining += search(q.que, &q.count, q.index, tracker);
			else
			{
				path = conclude_path(q.que, tracker, q.index);
				if (path != NOT_FOUND)
					break ;
			}
			q.que[q.index]->crossed = g_crossed;
		}
		q.index++;
	}
	g_crossed++;
	return (path);
}
