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

int	assing_ants(char *line)
{
	int	i;

	if (g_ant != 0)
		return (0);
	i = 0;
	while (line[i] != 0)
		validate_ants(line[i++]);
	g_ant = ft_atoi(line);
	check_ant_amount();
	return (1);
}

void	assign_room(char *line, int room_type)
{
	t_room	*room;
	char	**split;

	room = (t_room *)malloc(sizeof(t_room));
	//do start and end room
	room->ant = 0;
	split = ft_strsplit(line, ' ');
	room->name = ft_strdup(split[0]);
	//hash_room(room);
	ft_strdel(split);
	ft_printf("\nroom: %s | type: %d\n", line, room_type);
}
