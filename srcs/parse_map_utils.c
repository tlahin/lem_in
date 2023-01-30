/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:37:09 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:53:26 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Parses line for start and end commands
** to know next room is a 'special' room
*/
void	read_command(char *line, int *room_type, t_lem_in *lem_in)
{
	check_duplicate_command(*room_type, lem_in);
	if (!ft_strcmp(line, "##start"))
		*room_type = START_ROOM;
	else if (!ft_strcmp(line, "##end"))
		*room_type = END_ROOM;
}

void	double_str_size(void **mem, int size, t_lem_in *lem_in)
{
	char	*insurance_str;

	insurance_str = (char *)ft_memalloc(sizeof(char) * (size * 2));
	check_malloc((void *)insurance_str, lem_in);
	ft_memcpy(insurance_str, *mem, size);
	free(*mem);
	*mem = insurance_str;
}
