/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:35:20 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:53:09 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	new_hash_slot(t_table *slot, t_room *room)
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

int	check_existing_slot(t_table **last, char *room_name)
{
	t_table *new_collision;

	new_collision = *last;
	while (new_collision != NULL)
	{
		if (ft_strcmp(new_collision->room->name, room_name) == 0)
			return (0);
		*last = new_collision;
		new_collision = new_collision->next;
	}
	return (1);
}

int	hash_room(t_room *room)
{
	unsigned int	index;
	t_table	*last_slot;

	index = hash_value(room->name);
	if (g_table[index].room == NULL)
		return (new_hash_slot(&g_table[index], room));
	last_slot = &g_table[index];
	if (check_existing_slot(&last_slot, room->name) == 0)
		return (0);
	last_slot->next = (t_table *)ft_memalloc(sizeof(t_table));
	return (new_hash_slot(last_slot->next, room));
}

t_room	*get_room(char *key)
{
	t_table *tmp;

	if (key)
	{
		tmp = &g_table[hash_value(key)];
		while (tmp->room->name && ft_strcmp(tmp->room->name, key) != 0)
			tmp = tmp->next;
		if (tmp)
			return (tmp->room);
	}
	return (NULL);
}
