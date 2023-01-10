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

/*
** Validate and start and end rooms to global variables
*/

static void	assign_special_room(t_room *room, int room_type)
{
	check_duplicate_special(room, room_type);
	if (room_type == START_ROOM)
		g_table->start = room;
	else if (room_type == END_ROOM)
		g_table->end = room;
}

/*
** Check if variable is already assigned
** Check if the given input is usable (positive number)
*/

int	assing_ants(char *line)
{
	int	i;

	if (g_table->ants != 0)
		return (0);
	i = 0;
	while (line[i] != 0)
		validate_ants(line[i++]);
	g_table->ants = ft_atoi(line);
	check_ant_amount();
	return (1);
}

/*
** Create a room variable to store data
** Parse input line for name and cordinates
** Init rest of the variables
** Validate hash result and collected data
*/

void	assign_room(char *line, int room_type)
{
	t_room	*room;
	char	**split;
	int		hash_result;

	room = (t_room *)malloc(sizeof(t_room));
	check_malloc(room);
	assign_special_room(room, room_type);
	split = ft_strsplit(line, ' ');
	room->name = ft_strdup(split[0]);
	room->steps = 0;
	room->ant = 0;
	room->prev = NULL;
	room->next = NULL;
	room->link = NULL;
	hash_result = hash_room(room);
	check_valid_room(split, room, line, hash_result);
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	ft_arrdel(&split);
}

/*
** Create a link variable to store data
** Parse input line for the two (2) rooms
** Validate input
** Link the rooms together
*/

void	assign_link(char *line)
{
	char	**split;
	t_room	*room_1;
	t_room	*room_2;

	split = ft_strsplit(line, '-');
	room_1 = get_room(split[0]);
	room_2 = get_room(split[1]);
	check_valid_link(room_1, room_2, split, line);
	add_link(room_1, room_2);
	add_link(room_2, room_1);
	ft_arrdel(&split);
}
