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

static void	mixed_augment(t_link *rev_link, int r_index)
{
	int	i;
	int	step_count;

	i = r_index;
	step_count = 1;
	while (i > -1)
	{
		if (rev_link[i].flow == BACKWARD)
			delete_backward_link(rev_link, i);
		else
		{
			if (i < r_index && rev_link[i + 1].flow == BACKWARD)
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

static void	pure_forward_augment(t_link *rev_link, int r_index)
{
	int	step_count;

	step_count = 1;
	while (r_index > -1)
	{
		set_flow(rev_link[r_index].to->link, rev_link[r_index].from, USED_FORWARD);
		rev_link[r_index].from->prev = rev_link[r_index].to;
		rev_link[r_index].to->next = rev_link[r_index].from;
		rev_link[r_index].from->steps = step_count++;
		r_index--;
	}
}

int	augment(t_link *rev_link, int r_index, t_room *old_long_room, int backward)
{
	if (old_long_room != 0)
		remove_old_longer_path(old_long_room);
	if	(backward == BACKWARD)
	{
		mixed_augment(rev_link, r_index - 1);
		return (BACKWARD);
	}
	else
		pure_forward_augment(rev_link, r_index - 1);
	return (USED_FORWARD);
}
