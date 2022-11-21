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
	static int	start_end;

	if (line[0] != '#')
	{
		if (*stage == 1 || ft_strchr(line, '-'))
		{
			//assign
			ft_printf("link: %s\n", line);
			*stage = 1;
		}
		else if (ft_strlen(line) > 1)
		{
			//assign
			ft_printf("room: %s\n", line);
			start_end = 0;
		}
		else if (ft_strlen(line) == 1 && ft_isdigit(line[0]))
		{
			//assign
			main_struct->ants = (unsigned int)atoi(&line[0]);
			ft_printf("ants: %u\n", main_struct->ants);
		}
	}
	else
		read_command(line, &start_end);
}

static void	parse_map(int ret, char *str, t_lem_in *main_struct)
{
	int		stage;
	t_line	line;
	char	current_line[500];

	line.start = 0;
	line.end = 0;
	stage = 0;
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
