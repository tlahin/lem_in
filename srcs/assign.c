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
static void	assign_special_room(t_room *room, int room_type, t_lem_in *lem_in)
{
	check_duplicate_special(room, room_type, lem_in);
	if (room_type == START_ROOM)
		lem_in->table->start = room;
	else if (room_type == END_ROOM)
		lem_in->table->end = room;
}

/*
** Check if variable is already assigned
** Check if the given input is usable (positive number)
*/
int	assing_ants(char *line, t_lem_in *lem_in)
{
	int	i;

	if (lem_in->table->ants != 0)
		return (0);
	i = 0;
	while (line[i] != 0)
		validate_ants(line[i++], lem_in);
	lem_in->table->ants = ft_atoi(line);
	check_ant_amount(lem_in);
	return (1);
}

/*
** Create a room variable to store data
** Parse input line for name and cordinates
** Init rest of the variables
** Validate hash result and collected data
*/
void	assign_room(char *line, int room_type, t_lem_in *lem_in)
{
	t_room	*room;
	char	**split;
	int		hash_result;

	room = (t_room *)malloc(sizeof(t_room));
	check_malloc(room, lem_in);
	assign_special_room(room, room_type, lem_in);
	split = ft_strsplit(line, ' ');
	room->name = ft_strdup(split[0]);
	room->steps = 0;
	room->ant = 0;
	room->prev = NULL;
	room->next = NULL;
	room->link = NULL;
	hash_result = hash_room(room, lem_in);
	if (check_multiple_char(line, ' ', 2) == FAIL)
		free_and_exit(lem_in);
	check_valid_room(split, room, hash_result, lem_in);
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
void	assign_link(char *line, t_lem_in *lem_in)
{
	char	**split;
	t_room	*room_1;
	t_room	*room_2;

	split = ft_strsplit(line, '-');
	room_1 = get_room(split[0], lem_in);
	room_2 = get_room(split[1], lem_in);
	if (room_1 == lem_in->table->start && room_2 == lem_in->table->end)
		lem_in->table->start_end_connected = 1;
	if (check_multiple_char(line, '-', 1) == FAIL)
		free_and_exit(lem_in);
	check_valid_link(room_1, room_2, split, lem_in);
	add_link(room_1, room_2, lem_in);
	add_link(room_2, room_1, lem_in);
	ft_arrdel(&split);
}
