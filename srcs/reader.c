/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:48:06 by tlahin            #+#    #+#             */
/*   Updated: 2022/11/15 08:48:07 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	reader(int fd)
{
	char	*line;

	if (get_next_line(fd, &line) == -1)
	{
		ft_printf("Error reading the file\n");
		return (-1);
	}
	else
	{
		ft_printf("line: %s\n", line);
		return (0);
	}
}
