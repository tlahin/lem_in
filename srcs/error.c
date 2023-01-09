/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:52:48 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 13:52:50 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	validate_ants(char c)
{
	if (!ft_isdigit(c))
	{
		ft_printf("ERROR: Invalid ants\n");
		kill_and_quit();
	}
}

void	check_ant_amount(void)
{
	if (g_table->ants < 1)
	{
		ft_printf("ERROR: Invalid ant amount\n");
		kill_and_quit();
	}
}

void	check_empty_file(void)
{
	if (g_map[0] == 0)
	{
		ft_printf("ERROR: No map found\n");
		kill_and_quit();
	}
}

void	check_malloc(void *mem)
{
	if (mem == NULL)
	{
		ft_printf("ERROR: Failed to allocate memory\n");
		kill_and_quit();
	}
}

int	check_valid_line(char *line)
{
	if (line[0] == 0 || line[0] == '\n' || line[0] == 'L')
	{
		ft_printf("ERROR: Bad line\n");
		return (FAIL);
	}
	return (OK);
}

