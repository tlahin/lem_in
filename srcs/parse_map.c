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

static void	parse_line(char *line, int *stage, t_lem_in *main_struct)
{
	static int room_type;

	if (line[0] != '#')
	{
		check_valid_line(line);
		if (main_struct->ants_checked != OK)
			ant_check(line, main_struct);
		else if (*stage == 1 || ft_strchr(line, '-'))
		{
			//assign_link();
			*stage = 1;
			ft_printf("link: %s\n", line);
		}
		else
		{
			assign_room(line, room_type, main_struct);
			room_type = NORMAL_ROOM;
		}
	}
	else
		read_command(line, &room_type);
}

static void	parse_map(int ret, char *str, t_lem_in *main_struct)
{
	t_line	line;
	char	current_line[500];
	int		stage;

	stage = 0;
	line.start = 0;
	line.end = 0;
	while (line.start < ret)
	{
		line.index = 0;
		while (str[line.end] != '\n' && line.end < ret)
			current_line[line.index++] = str[line.end++];
		current_line[line.index] = 0;
		parse_line(current_line, &stage, main_struct);
		line.end++;
		line.start = line.end;
	}
}

int	read_map(t_lem_in *main_struct)
{
	char	*str;
	int		ret;

	str = (char *)malloc(sizeof(char) * 10000);
	ret = read(0, str, 10000);
	parse_map(ret, str, main_struct);
	return (OK);
}
