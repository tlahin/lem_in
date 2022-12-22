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

#include "../includes/lem_in.h"

static void	do_start_end(t_room *room, int room_type)
{
	check_duplicates_special(room, room_type);
	if (room_type == START_ROOM)
		g_table->start = room;
	else if (room_type == END_ROOM)
		g_table->end = room;
}

int	assing_ants(char *line, t_parser *p)
{
	int	i;

	if (p->ants != 0)
		return (0);
	i = 0;
	while (line[i] != 0)
		validate_ants(line[i++]);
	p->ants = ft_atoi(line);
	check_ant_amount(p);
	return (1);
}

void	assign_room(char *line, int room_type)
{
	t_room	*room;
	char	**split;
	int		hash_result;

	room = (t_room *)malloc(sizeof(t_room));
	do_start_end(room, room_type);
	split = ft_strsplit(line, ' ');
	room->name = ft_strdup(split[0]);
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	hash_result = hash_room(room);
	check_valid_room(split, room, line, hash_result);
	ft_arrdel(&split);
	ft_printf("%s\n", line);
}

void	assign_link(char *line)
{
	char	**split;
	t_room	*room_1;
	t_room	*room_2;

	split = ft_strsplit(line, '-');
	room_1 = get_room(split[0]);
	room_2 = get_room(split[1]);
	check_valid_link(room_1, room_2, split, line);
	add_elist(room_1, room_2);
	add_elist(room_2, room_1);
	ft_arrdel(&split);
}
