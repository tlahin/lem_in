/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:52:38 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:52:40 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_duplicate_command(int room_type)
{
	if (room_type != NORMAL_ROOM)
	{
		ft_printf("ERROR: error in command input\n");
		teminate_program();
	}
}

void	check_missing_special(void)
{
	if (!g_table->start || !g_table->end)
	{
		if(g_table->start == NOT_FOUND)
			ft_printf("ERROR: start room not found\n");
		if (g_table->end == NOT_FOUND)
			ft_printf("ERROR: end room not found\n");
		teminate_program();
	}
}

void	check_special_path(int path)
{
	if (path == NOT_FOUND)
	{
		ft_printf("ERROR: No path available\n");
		teminate_program();
	}
}

void	check_duplicate_special(t_room *room, int room_type)
{
	if (room_type == START_ROOM && g_table->start != NULL)
	{
		ft_printf("ERROR: duplicate start\n");
		free(room);
		teminate_program();
	}
	if (room_type == END_ROOM && g_table->end != NULL)
	{
		ft_printf("ERROR: duplicate end\n");
		free(room);
		teminate_program();
	}
}
