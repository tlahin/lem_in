/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:07:09 by tlahin            #+#    #+#             */
/*   Updated: 2022/11/21 14:07:11 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	assing_ants(char *line)
{
	int	i;

	if (g_ant != 0)
		return (0);
	i = 0;
	while (line[i] != 0)
		validate_ants(line[i++]);
	g_ant = ft_atoi(line);
	check_ant_amount();
	return (1);
}

void	assign_room(char *line, int room_type)
{
	t_room	*room;
	char	**split;
	int		hash_result;

	room = (t_room *)malloc(sizeof(t_room));
	//do start and end room
	ft_printf("%s\n", line);
	if (room_type == 2)
		ft_printf("%d\n", room_type);
	split = ft_strsplit(line, ' ');
	room->name = ft_strdup(split[0]);
	hash_result = hash_room(room);
	if (hash_result != OK)
		ft_printf("Oops, hash not gucci\n");
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	ft_strdel(split);
}
