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
# define SIZE			30000
# define STRING_SIZE	1000000

# define FOUND			1
# define NOT_FOUND		0

# define UNUSED			0
# define BACKWARD		-1
# define USED_FORWARD	1

typedef struct s_room		t_room;
typedef struct s_link		t_link;
typedef struct s_line		t_line;
typedef struct s_parser		t_parser;
typedef struct s_lemin		t_lemin;
typedef struct s_table		t_table;
typedef struct s_que		t_que;
typedef struct s_tracker	t_tracker;
typedef struct s_path		t_path;
typedef struct s_ant_distr	t_ant_distr;
typedef struct s_flags		t_flags;
typedef struct s_lem_in		t_lem_in;
typedef struct s_mover		t_mover;

struct s_room
{
	char	*name;
	int		steps;
	int		ant;
	int		x;
	int		y;
	t_link	*link;
	t_room	*prev;
	t_room	*next;
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
	int		ants;
	int		start_end_connected;
};

struct s_line
{
	int	start;
	int	end;
	int	index;
};

struct s_flags
{
	int	line;
	int	no_map;
	int	no_distr;
};

struct	s_que
{
	int		count;
	int		index;
	int		path;
	int		remaining;
	t_link	*que[SIZE];
};

struct s_tracker
{
	int	index;
	int	steps;
};

struct s_path
{
	int		total_steps;
	int		ant_count;
	t_room	**rooms;
};

struct s_ant_distr
{
	int		str_size;
	char	*line;
};

struct s_lem_in
{
	t_table	table[HASH_SIZE];
	int		crossed;
	int		optimal_path_count;
	int		optimal_line_count;
	char	*map;
	t_path	*paths[SIZE];
	int		backwards_link_used;
};

struct s_mover
{
	t_ant_distr	distr;
	t_room		**room;
	int			cur_ant;
	int			p_index;
	int			room_idx;
};

/*
** Main stuff
*/

int		main(int ac, char **av);

/*
** Init
*/

void	init_variables(t_lem_in *lem_in, int *path_found, t_flags *flags);
void	init_que(t_que *q, t_link *start);
void	init_path(int *r_index, t_room **old, t_lem_in *lem_in);
void	init_ant_movement(t_ant_distr *distr, t_lem_in *lem_in);
void	init_mover(t_mover *mover);

/*
** Map processing
*/

int		parse_map(t_lem_in *lem_in);
void	read_command(char *line, int *room_type, t_lem_in *lem_in);
void	double_str_size(void **mem, int size, t_lem_in *lem_in);

/*
** Assign
*/

int		assing_ants(char *line, t_lem_in *lem_in);
void	assign_room(char *line, int room_type, t_lem_in *lem_in);
void	assign_link(char *line, t_lem_in *lem_in);

/*
** Hash
*/

int		check_existing_slot(t_table **last, char *room_name);
int		hash_room(t_room *room, t_lem_in *lem_in);
t_room	*get_room(char *key, t_lem_in *lem_in);

/*
** Error
*/

void	validate_ants(char c, t_lem_in *lem_in);
void	check_ant_amount(t_lem_in *lem_in);
void	check_malloc(void *mem, t_lem_in *lem_in);
int		check_valid_line(char *line, t_lem_in *lem_in);
void	check_empty_file(t_lem_in *lem_in);

/*
** Room errors
*/

void	check_valid_room(char **split, t_room *room, \
		int hash_ret, t_lem_in *lem_in);
int		check_multiple_char(char *line, char c, int amount);

/*
** Link errors
*/

void	check_links(int stage, t_lem_in *lem_in);
void	check_valid_link(t_room *r1, t_room *r2, \
		char **split, t_lem_in *lem_in);

/*
** Special errors
*/

void	check_missing_special(t_lem_in *lem_in);
void	check_duplicate_command(int room_type, t_lem_in *lem_in);
void	check_path(int path_found, t_lem_in *lem_in);
void	check_duplicate_special(t_room *room, int room_typ, t_lem_in *lem_in);

/*
** Free
*/

void	free_path(t_path **paths, int p_count);
void	free_room_content(t_room *room);
void	free_everything(t_lem_in *lem_in);

/*
** Utilities
*/

t_link	*add_link(t_room *from_room, t_room *to_room, t_lem_in *lem_in);
void	set_link(t_link *link, t_room *from, t_room *to, int flow);
void	free_and_exit(t_lem_in *lem_in);
void	set_tracker(t_tracker *tracker, int index, int steps);
void	set_special_path(t_path **path, t_lem_in *lem_in);

/*
** Options
*/

void	options(int ac, char **av, t_flags *flags, t_lem_in *lem_in);
void	now_handle_it(t_flags *flags, t_lem_in *lem_in);

/*
** Bfs
*/

int		bfs(t_link *start, t_lem_in *lem_in);

/*
** Search
*/

int		search(t_link **que, int *q_count, int idx, t_tracker *tracker);

/*
** Augment
*/

int		augment(t_link *rev_link, int r_i, t_room *old_room, t_lem_in *lem_in);

/*
** Augment utilities
*/

void	set_flow(t_link *list, t_room *target_room, int flow);
void	delete_forward_room(t_room *room);
void	delete_prev_room(t_room *room);
void	remove_old_longer_path(t_room *room, t_lem_in *lem_in);

/*
** Algo
*/

int		pathfinder(t_lem_in *lem_in);

/*
** Sort
*/

void	sort_paths(t_path **path, int low, int high);

/*
** Mover
*/

void	insert_ant(t_mover *mover, t_lem_in *lem_in, \
		int ant_num, char *room_name);
void	ant_movement(t_lem_in *lem_in);
void	special_move(t_lem_in *lem_in);

#endif
