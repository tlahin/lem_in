/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:37:00 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:53:31 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Sort commands from the rest of the data (ants, rooms, links)
** and feed the parsed lines to corresponding functions
*/

static void	process_line(char *line, int *stage, t_lem_in *lem_in)
{
	static int	room_type;

	if (line[0] != '#')
	{
		check_valid_line(line, lem_in);
		if (assing_ants(line, lem_in))
			return ;
		if (*stage == 1 || ft_strchr(line, '-'))
		{
			assign_link(line, lem_in);
			*stage = 1;
		}
		else
		{
			assign_room(line, room_type, lem_in);
			room_type = NORMAL_ROOM;
		}
	}
	else
		read_command(line, &room_type, lem_in);
}

/*
** Save the entire map into a global variable g_map
** Parse one (1) line (ending with '\n') and process it
*/

int	parse_map(t_lem_in *lem_in)
{
	t_line	line;
	char	current_line[500];
	int		stage;
	int		read_amount;

	line.start = 0;
	line.end = 0;
	stage = 0;
	read_amount = read(0, lem_in->map, STRING_SIZE);
	while (line.start < read_amount)
	{
		line.index = 0;
		while (lem_in->map[line.end] != '\n' && line.end < read_amount)
			current_line[line.index++] = lem_in->map[line.end++];
		current_line[line.index] = 0;
		process_line(current_line, &stage, lem_in);
		line.end++;
		line.start = line.end;
	}
	check_empty_file(lem_in);
	check_missing_special(lem_in);
	check_links(stage, lem_in);
	return (OK);
}
