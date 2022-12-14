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
	//check dups
	if (!ft_strcmp(line, "##start"))
		*room_type = START_ROOM;
	else if (!ft_strcmp(line, "##end"))
		*room_type = END_ROOM;
}

int	check_valid_line(char *line)
{
	if (line[0] == 0 || line[0] == '\n' || line[0] == 'L')
	{
		ft_printf("ERROR: bad line\n");
		return (FAIL);
	}
	return (OK);
}

void	validate_ants(char c)
{
	if (!ft_isdigit(c))
	{
		ft_printf("ERROR: What kind of ant is this???\n");
		//teminate_program();
	}
}

void	check_ant_amount(t_parser *p)
{
	if (p->ants < 1)
	{
		ft_printf("ERROR: Bad ant amount\n");
		//teminate_program();
	}
}