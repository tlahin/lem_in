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

void	insert_ant(t_ant_distr *distr, char *room_name, int ant_num)
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
		double_str_size((void **)&distr->line, distr->str_size);
	}
}

static void	move_to_next(t_ant_distr *distr, t_room *room, t_room *next)
{
	if (room->ant != 0)
	{
		insert_ant(distr, next->name, room->ant);
		if (next != g_table->end)
			next->ant = room->ant;
		else
			next->ant++;
		room->ant = 0;
	}
}

static void	first_step(t_ant_distr *distr,
	t_room *room, t_path *cur_path, int *cur_ant)
{
	room->ant = *cur_ant;
	(*cur_ant)++;
	cur_path->ant_count--;
	insert_ant(distr, room->name, room->ant);
}

void	move_the_bois(void)
{
	int			path_index;
	int			room_index;
	int			cur_ant;
	t_room		**room;
	t_ant_distr	distr;

	cur_ant = 1;
	init_ant_movement(&distr);
	while (g_table->end->ant < g_table->ants)
	{
		path_index = 0;
		distr.line[0] = 0;
		while (path_index < g_optimal_path_count)
		{
			room = g_optimal_paths[path_index]->rooms;
			room_index = g_optimal_paths[path_index]->total_steps - 1;
			while (--room_index >= 0)
				move_to_next(&distr, room[room_index], room[room_index + 1]);
			if (cur_ant <= g_table->ants && g_optimal_paths[path_index]->ant_count > 0)
				first_step(&distr, room[0], g_optimal_paths[path_index], &cur_ant);
			path_index++;
		}
		ft_putendl(distr.line);
	}
	ft_memdel((void **)&distr.line);
}
