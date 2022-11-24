/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:29:08 by tlahin            #+#    #+#             */
/*   Updated: 2022/11/24 12:29:10 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static unsigned int	hash_value(char *key)
{
	unsigned long long	value;
	int					i;

	i = 0;
	value = 0;
	while (key[i])
		value = value * 42 + key[i++];
	value %= HASH_SIZE;
	return ((unsigned int)value);
}

int	hash_room(t_room *room, t_lem_in *main_struct)
{
	unsigned int	index;
	t_room_list		*last_slot;

	index = hash_value(room->name);
	if (!main_struct->hash_table[index].room)
		return (set_new_hash_slot(&main_struct->hash_table[index], room));
	last_slot = &main_struct->hash_table[index];
	//check if room exists
	last_slot->next = (t_room_list *)ft_memalloc(sizeof(t_room_list));
	return (set_new_hash_slot(last_slot->next, room));
}
