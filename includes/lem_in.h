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

typedef struct s_room		t_room;
typedef struct s_link		t_link;
typedef struct s_line		t_line;
typedef struct s_parser		t_parser;
typedef struct s_lemin		t_lemin;
typedef struct s_table		t_table;

struct s_room
{
	char	*name;
	int		ant;
	int		x;
	int		y;
	t_link	*link;
};

struct s_link
{
	int		crossed;
	int		flow;
	t_room	*from;
	t_room	*to;
	t_link	*next;
};

struct s_table
{
	t_room	*room;
	t_table	*next;
	t_room	*start;
	t_room	*end;
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

extern t_table g_table[HASH_SIZE];

/*
** Main stuff
*/

int		main(int ac, char **av);

/*
** Map processing
*/

int		parse_map(t_parser *parser);
int		check_valid_line(char *line);
void	read_command(char *line, int *room_type);
void	check_duplicate_command(int room_type);

/*
** Assign
*/

int		assing_ants(char *line, t_parser *parser);
void	assign_room(char *line, int room_type);
void	assign_link(char *line);

/*
** Hash
*/

int		check_existing_slot(t_table **last, char *room_name);
int		hash_room(t_room *room);
t_room	*get_room(char *key);

/*
** Error
*/

void	validate_ants(char c);
void	check_ant_amount(t_parser *p);
void	check_malloc(void *mem);

void	check_duplicates_special(t_room *room, int room_state);
void	check_valid_room(char **split, t_room *room, char *line, int hsh_result);
int		check_multiple_char(char *line, char c, int ammount);

void	check_valid_link(t_room *r1, t_room *r2, char **split, char *line);

/*
** Free
*/

void	free_room_content(t_room *room);
void	free_everything(void);

/*
** Utilities
*/

t_link	*add_elist(t_room *from_room, t_room *to_room);
void	set_link(t_link *link, t_room *from, t_room *to, int flow);
void	teminate_program(void);

#endif
