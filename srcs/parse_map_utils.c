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

#include "../includes/lem_in.h"

void	read_command(char *line, int *room_type)
{
	check_duplicate_command(*room_type);
	if (!ft_strcmp(line, "##start"))
		*room_type = START_ROOM;
	else if (!ft_strcmp(line, "##end"))
		*room_type = END_ROOM;
}