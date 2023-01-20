/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   augment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:51:48 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:51:50 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	delete_backward_link(t_link *rev_link, int i)
{
	delete_forward_room(rev_link[i].from);
	if (i > 0 && rev_link[i - 1].flow == BACKWARD)
		delete_prev_room(rev_link[i].from);
}

/*
** Corrects the pathing and the 'flow'
*/

static void	mixed_augment(t_link *rev_link, int r_i)
{
	int	i;
	int	step_count;

	i = r_i;
	step_count = 1;
	while (i > -1)
	{
		if (rev_link[i].flow == BACKWARD)
			delete_backward_link(rev_link, i);
		else
		{
			if (i < r_i && rev_link[i + 1].flow == BACKWARD)
				step_count = rev_link[i].to->steps + 1;
			rev_link[i].from->steps = step_count++;
			if (i > 0 && rev_link[i - 1].flow == BACKWARD)
				delete_prev_room(rev_link[i].from);
			rev_link[i].to->next = rev_link[i].from;
			rev_link[i].from->prev = rev_link[i].to;
			set_flow(rev_link[i].to->link, rev_link[i].from, USED_FORWARD);
		}
		i--;
	}
}

static void	pure_forward_augment(t_link *rev_link, int r_i)
{
	int	step_count;

	step_count = 1;
	while (r_i > -1)
	{
		set_flow(rev_link[r_i].to->link, rev_link[r_i].from, USED_FORWARD);
		rev_link[r_i].from->prev = rev_link[r_i].to;
		rev_link[r_i].to->next = rev_link[r_i].from;
		rev_link[r_i].from->steps = step_count++;
		r_i--;
	}
}

/*
** Augments the path found during last bfs call
*/

int	augment(t_link *rev_link, int rev_idx, t_room *old_room, int backward)
{
	if (old_room != 0)
		remove_old_longer_path(old_room);
	if (backward == BACKWARD)
	{
		mixed_augment(rev_link, rev_idx - 1);
		return (BACKWARD);
	}
	else
		pure_forward_augment(rev_link, rev_idx - 1);
	return (USED_FORWARD);
}
