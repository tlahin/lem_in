/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   augment_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:51:33 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:51:37 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_flow(t_link *list, t_room *target_room, int flow)
{
	if (target_room != NULL)
	{
		while (list && list->to != target_room)
			list = list->next;
		list->flow = flow;
	}
}

void	delete_forward_room(t_room *room)
{
	set_flow(room->link, room->next, UNUSED);
	room->next = 0;
}

void	delete_prev_room(t_room *room)
{
	set_flow(room->link, room->prev, UNUSED);
	room->prev = 0;
}

void	remove_old_longer_path(t_room *room)
{
	t_room	*temp;
	t_room	*final;

	final = NULL;
	temp = NULL;
	while (room != g_table->start)
	{
		final = temp;
		temp = room->prev;
		delete_forward_room(room->prev);
		delete_prev_room(room);
		room = temp;
	}
	set_flow(room->link, final, UNUSED);
}
