/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:33:36 by tlahin            #+#    #+#             */
/*   Updated: 2022/11/08 09:33:38 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		ft_printf("Input file error\n");
	else
		fd = open(av[1], O_RDONLY);
		if (reader(fd) == 0)
			ft_printf("Success\n");
	return (0);
}
