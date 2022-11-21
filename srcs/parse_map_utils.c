/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:37:09 by tlahin            #+#    #+#             */
/*   Updated: 2022/11/21 12:37:11 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_valid_line(char *line)
{
	if (line[0] == 0 || line[0] == '\n' || line[0] == 'L')
	{
		ft_printf("ERROR: bad line\n");
		exit(FAIL);
	}
	return (OK);
}

void	read_command(char *str, int *room_type)
{
	if (ft_strcmp(str, "##start"))
		*room_type = START_ROOM;
	else if (ft_strcmp(str, "##end"))
		*room_type = END_ROOM;
}