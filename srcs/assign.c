/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:07:09 by tlahin            #+#    #+#             */
/*   Updated: 2022/11/21 14:07:11 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	assign_room(char *line, int room_type, t_lem_in *main_struct)
{
	t_room	*room;
	char	**split;

	room = (t_room *)malloc(sizeof(t_room));
	//do start and end room
	room->ant = 0;
	split = ft_strsplit(line, ' ');
	room->name = ft_strdup(split[0]);
	room->hash = hash_room(room, main_struct);
	//valid?
	ft_strdel(&split);
	ft_printf("room: %s, ", line);
	ft_printf("type: %d\n", room_type);
}
