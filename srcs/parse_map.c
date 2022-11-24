/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:37:00 by tlahin            #+#    #+#             */
/*   Updated: 2022/11/21 12:37:02 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			//links
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

static void	parse_map(int ret, char *str)
{
	t_line	line;
	char	current_line[500];
	int		stage;

	line.start = 0;
	line.end = 0;
	stage = 0;
	while (line.start < ret)
	{
		line.index = 0;
		while (str[line.end] != '\n' && line.end < ret)
			current_line[line.index++] = str[line.end++];
		current_line[line.index] = 0;
		process_line(current_line, &stage);
		line.end++;
		line.start = line.end;
	}
}

int	read_map(void)
{
	int		ret;
	char	*str;

	str = NULL;
	ret = read(0, str, STRING_SIZE);
	parse_map(ret, str);
	return (OK);
}
