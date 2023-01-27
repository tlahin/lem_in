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

void	check_duplicate_command(int room_type, t_lem_in *lem_in)
{
	if (room_type != NORMAL_ROOM)
	{
		ft_printf("ERROR: Invalid command\n");
		free_and_exit(lem_in);
	}
}

void	check_missing_special(t_lem_in *lem_in)
{
	if (!lem_in->table->start || !lem_in->table->end)
	{
		if (lem_in->table->start == NOT_FOUND)
			ft_printf("ERROR: Start not found\n");
		if (lem_in->table->end == NOT_FOUND)
			ft_printf("ERROR: End not found\n");
		free_and_exit(lem_in);
	}
}

void	check_path(int path, t_lem_in *lem_in)
{
	if (path == NOT_FOUND)
	{
		ft_printf("ERROR: No path available\n");
		free_and_exit(lem_in);
	}
}

void	check_duplicate_special(t_room *room, int room_type, t_lem_in *lem_in)
{
	if (room_type == START_ROOM && lem_in->table->start != NULL)
	{
		ft_printf("ERROR: Duplicate start\n");
		free(room);
		free_and_exit(lem_in);
	}
	if (room_type == END_ROOM && lem_in->table->end != NULL)
	{
		ft_printf("ERROR: Duplicate end\n");
		free(room);
		free_and_exit(lem_in);
	}
}
