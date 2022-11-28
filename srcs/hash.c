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

int	hash_room(t_room *room)
{
	unsigned int	index;
	//t_room_list		last;

	index = hash_value(room->name);
	ft_printf("name: %s hash: %u\n\n", room->name, index);
	if (g_hashtable[index].room == NULL)
		return (new_hash_slot(&g_hashtable[index], room));
	return (OK);
}
