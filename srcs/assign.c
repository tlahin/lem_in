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

int	assing_ants(char *line, t_parser *p)
{
	int	i;

	if (p->ants != 0)
		return (0);
	i = 0;
	while (line[i] != 0)
		validate_ants(line[i++]);
	p->ants = ft_atoi(line);
	check_ant_amount();
	return (1);
}

void	assign_room(char *line, int room_type, t_parser *p)
{
	t_room	*room;
	char	**split;
	int		hash_result;

	room = (t_room *)malloc(sizeof(t_room));
	split = ft_strsplit(line, ' ');
	room->name = ft_strdup(split[0]);
	room->x = ft_strdup(split[1]);
	room->y = ft_strdup(split[2]);
	check_valid_room(room);
	hash_result = hash_room(room);
	ft_arrdel(&split);
	ft_printf("%s\n", line);

}
