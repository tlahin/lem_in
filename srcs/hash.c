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

static int	new_hash_slot(t_room_list *slot, t_room *room)
{
	slot->room = room;
	slot->next = NULL;
	return (OK);
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
	return ((unsigned int)value);
}

int	check_duplicate_hash(t_room_list **last, char *room_name)
{
	t_room_list	*new_collision;

	new_collision = *last;
	while (new_collision != NULL)
	{
		if (ft_strcmp(new_collision->room->name, room_name))
			return (ROOM_EXIST);
		*last = new_collision;
		new_collision = new_collision->next;
	}
	return (NEW_ROOM);
}

int	hash_room(t_room *room)
{
	unsigned int	index;
	t_room_list		*last;

	index = hash_value(room->name);
	ft_printf("name: %s hash: %u\n\n", room->name, index);
	if (g_hashtable[index].room == NULL)
		return (new_hash_slot(&g_hashtable[index], room));
	last = &g_hashtable[index];
	if (check_duplicate_hash(&last, room->name) == ROOM_EXIST)
		return (ROOM_EXIST);
	last->next = (t_room_list *)ft_memalloc(sizeof(t_room_list));
	return (new_hash_slot(last->next, room));
}

t_room	*get_room(char *key)
{
	t_room_list	*tmp;

	if (key)
	{
		tmp = &g_hashtable[hash_value(key)];
		while (tmp->room && ft_strcmp(tmp->room->name, key) != 0)
			tmp = tmp->next;
		if (tmp)
			return (tmp->room);
	}
	return (NULL);
}
