/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:52:59 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:53:00 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_path(t_path **paths, int p_count)
{
	int	i;

	i = 0;
	while (i < p_count)
	{
		ft_memdel((void **)&paths[i]->rooms);
		ft_memdel((void **)&paths[i]);
		i++;
	}
}

void	free_room_content(t_room *room)
{
	t_link	*link;

	ft_memdel((void **)&room->name);
	while (room->link)
	{
		link = room->link->next;
		ft_memdel((void **)&room->link);
		room->link = link;
	}
	free(room);
}

static void	free_hash_rooms(t_table *hash_slot)
{
	int		collision_count;
	t_table	*temp;

	collision_count = 0;
	while (hash_slot)
	{
		temp = hash_slot->next;
		free_room_content(hash_slot->room);
		hash_slot->room = NULL;
		if (collision_count > 0)
			ft_memdel((void **)&hash_slot);
		hash_slot = temp;
		collision_count++;
	}
}

static void	free_all_rooms(void)
{
	int	i;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (g_table[i].room)
			free_hash_rooms(&g_table[i]);
		i++;
	}
}

void	free_everything(void)
{
	free_all_rooms();
	if(g_map)
		ft_memdel((void **)&g_map);
	free_path(g_optimal_paths, g_optimal_path_count);
}
