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

typedef struct s_room_list	t_room_list;
typedef struct s_room		t_room;
typedef struct s_line		t_line;
typedef struct s_parser		t_parser;
typedef struct s_lemin		t_lemin;
typedef struct s_hash_table	t_hash_table;

struct s_room
{
	char	*name;
	int		ant;
	int		x;
	int		y;
	int		**links;
};

struct s_hash_table
{
	t_room			*room;
	t_hash_table	*next;
};

struct s_line
{
	int	start;
	int	end;
	int	index;
};

struct s_parser
{
	int		ants;
	char	*map;
	int		read_amount;
};

extern t_hash_table g_table[HASH_SIZE];

/*
** Main stuff
*/

int		main(int ac, char **av);
void	init_parser(t_parser *parser);

/*
** Map processing
*/

int		parse_map(t_parser *parser);
int		check_valid_line(char *line);
void	read_command(char *line, int *room_type);

/*
** Assign
*/

int		assing_ants(char *line, t_parser *parser);
void	assign_room(char *line, int room_type, t_parser *parser);

/*
** Hash
*/

int		hash_room(t_room *room);
int		check_existing_slot(t_room_list **last, char *room_name);
t_room	*get_room(char *key);

/*
** Error
*/

void	validate_ants(char c);
void	check_ant_amount(void);

#endif
