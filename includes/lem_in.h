/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:34:12 by tlahin            #+#    #+#             */
/*   Updated: 2022/11/08 09:34:14 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
** Includes
*/

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** Structs
*/

/*
** Main
*/

int	main(int ac, char **av);
int	reader(int fd);

#endif
