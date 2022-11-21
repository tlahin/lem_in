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

# define FAIL   -1
# define OK     0
# define NORMAL_ROOM 0
# define START_ROOM -1
# define END_ROOM 1

typedef struct s_lem_in		t_lem_in;
typedef struct s_room_list	t_room_list;
typedef struct s_room		t_room;
typedef struct s_line		t_line;

struct s_room
{
	char	*name;
	t_room	*next;
	t_room	*prev;
	int		ant;
};

struct s_room_list
{
	t_room		*room;
	t_room_list	*next;
};

struct s_line
{
	int	start;
	int	end;
	int	index;
};

struct s_lem_in
{
	unsigned int	ants;

};

/*
** Main stuff
*/

int			main(int ac, char **av);
t_lem_in	*init_struct(t_lem_in *main_struct);

/*
** Map processing
*/

int			read_map(void);
void		read_command(char *str, int *room_type);
int			ants_exist(char *line);
int			check_valid_line(char *line);

/*
** Assigning
*/

void		assign_room(char *line, int room_type);

#endif
