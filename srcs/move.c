/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:52:50 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 15:52:52 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Creates the string with the ants and rooms which will be prited
** at the end of every 'turn'
*/

void	insert_ant(t_ant_distr *distr, char *room_name, int ant_num, t_lem_in *lem_in)
{
	int		i;
	char	str[50];
	char	*ant_num_str;

	ft_bzero((void *)str, 50);
	str[0] = 'L';
	i = 1;
	ant_num_str = ft_itoa(ant_num);
	ft_strcpy(str + i, ant_num_str);
	free(ant_num_str);
	while (str[i])
		i++;
	str[i++] = '-';
	ft_strcpy(str + i, room_name);
	while (str[i])
		i++;
	str[i++] = ' ';
	ft_strcat(distr->line, str);
	if (distr->line[distr->str_size - 1] != 0)
	{
		distr->str_size = distr->str_size * 2;
		double_str_size((void **)&distr->line, distr->str_size, lem_in);
	}
}

static void	move_to_next(t_ant_distr *distr, t_room *room, t_room *next, t_lem_in *lem_in)
{
	if (room->ant != 0)
	{
		insert_ant(distr, next->name, room->ant, lem_in);
		if (next != lem_in->table->end)
			next->ant = room->ant;
		else
			next->ant++;
		room->ant = 0;
	}
}

static void	first_step(t_ant_distr *distr,
	t_room *room, t_path *cur_path, int *cur_ant, t_lem_in *lem_in)
{
	room->ant = *cur_ant;
	(*cur_ant)++;
	cur_path->ant_count--;
	insert_ant(distr, room->name, room->ant, lem_in);
}

void	special_move(t_lem_in *lem_in)
{
	int	cur_ant;

	cur_ant = 1;
	lem_in->optimal_line_count = 1;
	while (cur_ant <= lem_in->table->ants)
	{
		ft_printf("L%d-end", cur_ant);
		if (cur_ant <= lem_in->table->ants)
			write(1, " ", 1);
		cur_ant++;
	}
	ft_printf("\n");
}

/*
** Loops untill each ant has reached the 'end' room
** moves ants if possible printing a string each 'turn'
** string contains which ant has moved and where it moved
*/

void	ant_movement(t_lem_in *lem_in)
{
	int			p_index;
	int			room_idx;
	int			cur_ant;
	t_room		**room;
	t_ant_distr	distr;

	cur_ant = 1;
	init_ant_movement(&distr, lem_in);
	while (lem_in->table->end->ant < lem_in->table->ants)
	{
		p_index = 0;
		distr.line[0] = 0;
		while (p_index < lem_in->optimal_path_count)
		{
			room = lem_in->paths[p_index]->rooms;
			room_idx = lem_in->paths[p_index]->total_steps - 1;
			while (--room_idx >= 0)
				move_to_next(&distr, room[room_idx], room[room_idx + 1], lem_in);
			if (cur_ant <= lem_in->table->ants && lem_in->paths[p_index]->ant_count > 0)
				first_step(&distr, room[0], lem_in->paths[p_index], &cur_ant, lem_in);
			p_index++;
		}
		ft_putendl(distr.line);
	}
	ft_memdel((void **)&distr.line);
}
