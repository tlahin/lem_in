/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:53:51 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:53:52 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

//not occupied - UNUSED flow next
static int	not_occupied(t_room *prev_room, int next_flow)
{
	ft_printf("not_occupied\n");
	return (prev_room == NULL && next_flow == UNUSED);
}

// occupied - BACKWARD flow
static int	occ_backward(int current_flow)
{
	ft_printf("occ_back\n");
	return (current_flow == BACKWARD);
}

// occupiedd - UNUSED flow - BACKWARD flow next
static int	occ_unused_to_backward(int current_flow, int next_flow)
{
	ft_printf("occ_unused_to_back\n");
	return (current_flow == UNUSED && next_flow == BACKWARD);
}

// occupied - USED_FORWARD flow - USED_FORWARD flow next - less steps taken
static int	shorter_path(int next_flow, int old_steps, int current_steps)
{
	ft_printf("short\n");
	return (next_flow == USED_FORWARD && old_steps > current_steps);
}

/*
** Determine 'flow' direction
*/

int	search(t_link **que, int *q_count, int idx, t_tracker *tracker)
{
	int		room_count;
	t_link	*forward_link;

	room_count = 0;
	forward_link = que[idx]->to->link;
	while (forward_link)
	{
		if (forward_link->to != que[idx]->from)
		{
			if (forward_link->to == que[idx]->to->prev)
				forward_link->flow = BACKWARD;
			if (not_occupied(que[idx]->to->prev, forward_link->flow)
				|| occ_backward(que[idx]->flow)
				|| occ_unused_to_backward(que[idx]->flow, forward_link->flow)
				|| shorter_path(forward_link->flow,
					que[idx]->to->steps, tracker[idx].steps))
			{
				set_tracker(&tracker[*q_count], idx, tracker[idx].steps + 1);
				que[(*q_count)++] = forward_link;
				room_count++;
			}
		}
		forward_link = forward_link->next;
	}
	return (room_count);
}
