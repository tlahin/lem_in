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

static void	process_line(char *line, int *stage)
{
	static int	room_type;

	if (line[0] != '#')
	{
		check_valid_line(line);
		if (assing_ants(line))
			return ;
		if (*stage == 1 || ft_strchr(line, '-'))
		{
			assign_link(line);
			*stage = 1;
		}
		else
		{
			assign_room(line, room_type);
			room_type = NORMAL_ROOM;
		}
	}
	else
		read_command(line, &room_type);
}

int	parse_map()
{
	t_line	line;
	char	current_line[500];
	int		stage;
	int		read_amount;

	line.start = 0;
	line.end = 0;
	stage = 0;
	read_amount = read(0, g_map, STRING_SIZE);
	while (line.start < read_amount)
	{
		line.index = 0;
		while (g_map[line.end] != '\n' && line.end < read_amount)
			current_line[line.index++] = g_map[line.end++];
		current_line[line.index] = 0;
		process_line(current_line, &stage);
		line.end++;
		line.start = line.end;
	}
	check_empty_file();
	check_missing_special();
	check_links(stage);
	return (OK);
}
