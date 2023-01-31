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
void	insert_ant(t_room *room, t_mover *mover, t_lem_in *lem_in, int ant_num)
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
	ft_strcpy(str + i, room->name);
	while (str[i])
		i++;
	str[i++] = ' ';
	ft_strcat(mover->distr.line, str);
	if (mover->distr.line[mover->distr.str_size - 1] != 0)
	{
		mover->distr.str_size = mover->distr.str_size * 2;
		double_str_size((void **)&mover->distr.line, \
			mover->distr.str_size, lem_in);
	}
}

static void	move_to_next(t_mover *mover, t_lem_in *lem_in)
{
	t_room	*next;
	t_room	*cur_room;

	cur_room = mover->room[mover->room_idx];
	next = mover->room[mover->room_idx + 1];
	if (cur_room->ant != 0)
	{
		insert_ant(next, mover, lem_in, cur_room->ant);
		if (next != lem_in->table->end)
			next->ant = cur_room->ant;
		else
			next->ant++;
		cur_room->ant = 0;
	}
}

static void	first_step(t_mover *mover, t_lem_in *lem_in)
{
	t_room	*room;

	room = mover->room[0];
	mover->room[0]->ant = mover->cur_ant;
	mover->cur_ant++;
	lem_in->paths[mover->p_index]->ant_count--;
	insert_ant(room, mover, lem_in, mover->cur_ant);
}

void	special_move(t_lem_in *lem_in)
{
	int	cur_ant;

	cur_ant = 1;
	lem_in->optimal_line_count = 1;
	while (cur_ant <= lem_in->table->ants)
	{
		ft_printf("L%d-%s", cur_ant, lem_in->table->end->name);
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
	t_mover	mover;

	init_mover(&mover);
	init_ant_movement(&mover.distr, lem_in);
	while (lem_in->table->end->ant < lem_in->table->ants)
	{
		mover.p_index = 0;
		mover.distr.line[0] = 0;
		while (mover.p_index < lem_in->optimal_path_count)
		{
			mover.room = lem_in->paths[mover.p_index]->rooms;
			mover.room_idx = lem_in->paths[mover.p_index]->total_steps - 1;
			while (--mover.room_idx >= 0)
				move_to_next(&mover, lem_in);
			if (mover.cur_ant <= lem_in->table->ants \
				&& lem_in->paths[mover.p_index]->ant_count > 0)
				first_step(&mover, lem_in);
			mover.p_index++;
		}
		ft_putendl(mover.distr.line);
	}
	ft_memdel((void **)&mover.distr.line);
}
