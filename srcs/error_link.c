/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:52:17 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:52:18 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_links(int stage, t_lem_in *lem_in)
{
	if (stage == 0)
	{
		ft_printf("ERROR: No valid links\n");
		free_and_exit(lem_in);
	}
}

static int	check_empty_room(t_room *r1, t_room *r2)
{
	if (!r1 || !r2)
	{
		ft_printf("ERROR: Invalid line\n");
		return (FAIL);
	}
	return (OK);
}

static int	check_duplicate_link(t_room *a, t_room *b)
{
	t_link	*tmp;

	tmp = a->link;
	while (tmp)
	{
		if (ft_strcmp(tmp->to->name, b->name) == 0)
		{
			ft_printf("ERROR: Duplicate links\n");
			return (FAIL);
		}
		tmp = tmp->next;
	}
	return (OK);
}

void	check_valid_link(t_room *r1, t_room *r2, char **split, char *line, t_lem_in *lem_in)
{
	if (check_multiple_char(line, '-', 1) == FAIL
		|| check_empty_room(r1, r2) == FAIL
		|| check_duplicate_link(r1, r2) == FAIL)
	{
		ft_arrdel(&split);
		free_and_exit(lem_in);
	}
}
