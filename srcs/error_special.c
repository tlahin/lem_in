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
		ft_printf("ERROR: Invalid command\n");
		free_and_exit();
	}
}

void	check_missing_special(void)
{
	if (!g_table->start || !g_table->end)
	{
		if (g_table->start == NOT_FOUND)
			ft_printf("ERROR: Start not found\n");
		if (g_table->end == NOT_FOUND)
			ft_printf("ERROR: End not found\n");
		free_and_exit();
	}
}

void	check_path(int path)
{
	if (path == NOT_FOUND)
	{
		ft_printf("ERROR: No path available\n");
		free_and_exit();
	}
}

void	check_duplicate_special(t_room *room, int room_type)
{
	if (room_type == START_ROOM && g_table->start != NULL)
	{
		ft_printf("ERROR: Duplicate start\n");
		free(room);
		free_and_exit();
	}
	if (room_type == END_ROOM && g_table->end != NULL)
	{
		ft_printf("ERROR: Duplicate end\n");
		free(room);
		free_and_exit();
	}
}
