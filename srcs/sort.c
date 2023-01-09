/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:07:47 by tlahin            #+#    #+#             */
/*   Updated: 2023/01/05 14:07:48 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	swap_paths(t_path **a, t_path **b)
{
	t_path	*ptr;

	ptr = *a;
	*a = *b;
	*b = ptr;
}

static int	partition(t_path **path, int low, int high)
{
	int	pivot;
	int	index;

	pivot = path[high]->total_steps;
	index = low;
	while (low < high)
	{
		if (path[low]->total_steps < pivot)
		{
			if (low != index)
				swap_paths(&path[low], &path[index]);
			index++;
		}
		low++;
	}
	swap_paths(&path[index], &path[high]);
	return (index);
}

void	sort_paths(t_path **path, int low, int high)
{
	int	p_index;

	if (low < high)
	{
		p_index = partition(path, low, high);
		sort_paths(path, low, p_index - 1);
		sort_paths(path, p_index + 1, high);
	}
}
