/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:52:28 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:52:30 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	check_multiple_char(char *line, char c, int ammount)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (line[i])
		if (line[i++] == c)
			count++;
	if (count != ammount)
	{
		ft_printf("ERROR: Invalid line\n");
		return (FAIL);
	}
	return (OK);
}

static int	check_room_coordinates(char **split)
{
	int	i;
	int	room_status;

	i = 0;
	room_status = OK;
	while (split[1][i])
		if (ft_isdigit(split[1][i++]) == 0)
			room_status = FAIL;
	i = 0;
	while (split[2][i])
		if (ft_isdigit(split[2][i++]) == 0)
			room_status = FAIL;
	if (room_status == FAIL)
		ft_printf("ERROR: Invalid line\n");
	return (room_status);
}

static int	check_duplicate_room(int hash_result, t_room *room)
{
	if (hash_result == 0)
	{
		ft_printf("ERROR: Duplicate rooms\n");
		free_room_content(room);
		return (FAIL);
	}
	return (OK);
}

void	check_valid_room(char **split, t_room *room, char *line, int hsh_result)
{
	if (check_multiple_char(line, ' ', 2) == FAIL
		|| check_room_coordinates(split) == FAIL
		|| check_duplicate_room(hsh_result, room) == FAIL)
	{
		ft_arrdel(&split);
		kill_and_quit();
	}
}
