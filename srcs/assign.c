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

int	assing_ants(char *line, t_lem_in *main_struct)
{
	int	i;

	i = 0;
	if (main_struct->ants_checked != 0)
		return (FAIL);
	while (line[i] != 0)
		check_ants_char(line[i++]);
	main_struct->ants = ft_atoi(line);
	return (OK);
}

void	assign_room(char *line, int room_type, t_lem_in *main_struct)
{
	t_room	*room;
	char	**split;

	room = (t_room *)malloc(sizeof(t_room));
	//do start and end room
	room->ant = 0;
	split = ft_strsplit(line, ' ');
	room->name = ft_strdup(split[0]);
	hash_room(room, main_struct);
	ft_strdel(split);
	ft_printf("\nroom: %s | type: %d\n", line, room_type);
}
