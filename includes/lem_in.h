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

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define FAIL			-1
# define OK				0

# define NORMAL_ROOM	0
# define START_ROOM		-1
# define END_ROOM		1
# define HASH_SIZE		12000
# define STRING_SIZE	1000000

extern int					g_ant;

typedef struct s_lem_in		t_lem_in;
typedef struct s_hash		t_hash;
typedef struct s_room		t_room;
typedef struct s_line		t_line;

struct s_hash
{
	t_room	*room;
	t_hash	*next;
};

struct s_room
{
	char			*name;
	int				ant;
};

struct s_line
{
	int	start;
	int	end;
	int	index;
};

/*
** Main stuff
*/

int			main(int ac, char **av);
void		init_global(void);

/*
** Map processing
*/

int			read_map(void);
int			check_valid_line(char *line);
void		read_command(char *line, int *room_type);

/*
** Assign
*/

int		assing_ants(char *line);
void	assign_room(char *line, int room_type);

/*
** Error
*/

void    validate_ants(char c);
void    check_ant_amount(void);

#endif
