/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:35:20 by tlahin            #+#    #+#             */
/*   Updated: 2022/11/28 13:35:22 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lem_in.h"

static int	new_hash_slot(t_hash_table *slot, t_room *room)
{
	slot->room = room;
	slot->next = NULL;
	return (1);
}

static unsigned int	hash_value(char *key)
{
	int				i;
	unsigned int	value;

	i = 0;
	value = 0;
	while (key[i])
		value = value * 42 + key[i++];
	value %= HASH_SIZE;
	return (value);
}

int	hash_room(t_room *room)
{
	unsigned int	index;
	t_hash_table	*last_slot;

	index = hash_value(room->name);
	if (g_table[index].room == NULL)
		return (new_hash_slot(&g_table[index], room));
	last_slot = &g_table[index];
	if (check_existing_slot(&last_slot, room->name) == 0)
		return (0);
	last_slot->next = (t_hash_table *)ft_memalloc(sizeof(t_hash_table));
	return (new_hash_slot(last_slot->next, room));
}

t_room	*get_room(char *key)
{
	return (room);
}
