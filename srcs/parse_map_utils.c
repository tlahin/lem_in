/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:37:09 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:53:26 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	read_command(char *line, int *room_type)
{
	check_duplicate_command(*room_type);
	if (!ft_strcmp(line, "##start"))
		*room_type = START_ROOM;
	else if (!ft_strcmp(line, "##end"))
		*room_type = END_ROOM;
}

void	double_str_size(void **mem, int size)
{
	char	*insurance_str;

	insurance_str = (char *)ft_memalloc(sizeof(char) * (size * 2));
	check_malloc((void *)insurance_str);
	ft_memcpy(insurance_str, *mem, size);
	free(*mem);
	*mem = insurance_str;
}

void	insurance_reading(int *ret)
{
	int	total;

	if (*ret < STRING_SIZE)
		return ;
	total = *ret;
	while (*ret > 0)
	{
		double_str_size((void **)&g_map, total);
		*ret = read(0, &g_map[total], total);
		total += *ret;
	}
	*ret = total;
}
