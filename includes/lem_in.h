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
# define MAGIC_NUMBER	30000
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
	t_link	*que[MAGIC_NUMBER];
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

extern t_table				g_table[HASH_SIZE];
extern int					g_crossed;
extern int					g_optimal_path_count;
extern int					g_optimal_line_count;
extern t_path				*g_paths[MAGIC_NUMBER];
extern char					*g_map;

/*
** Main stuff
*/

int		main(int ac, char **av);

/*
** Init
*/

void	init_globals(int *path_found, t_flags *flags);
void	init_que(t_que *q, t_link *start);
void	init_path(int *r_index, int *backward_link_used, t_room **old);
void	init_ant_movement(t_ant_distr *distr);

/*
** Map processing
*/

int		parse_map(void);
void	read_command(char *line, int *room_type);
void	double_str_size(void **mem, int size);

/*
** Assign
*/

int		assing_ants(char *line);
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
void	check_ant_amount(void);
void	check_malloc(void *mem);
int		check_valid_line(char *line);
void	check_empty_file(void);

/*
** Room errors
*/

void	check_valid_room(char **split, t_room *room, char *line, int hash_ret);
int		check_multiple_char(char *line, char c, int amount);

/*
** Link errors
*/

void	check_links(int stage);
void	check_valid_link(t_room *r1, t_room *r2, char **split, char *line);

/*
** Special errors
*/

void	check_missing_special(void);
void	check_duplicate_command(int room_type);
void	check_path(int path_found);
void	check_duplicate_special(t_room *room, int room_type);

/*
** Free
*/

void	free_path(t_path **paths, int p_count);
void	free_room_content(t_room *room);
void	free_everything(void);

/*
** Utilities
*/

t_link	*add_link(t_room *from_room, t_room *to_room);
void	set_link(t_link *link, t_room *from, t_room *to, int flow);
void	free_and_exit(void);
void	set_tracker(t_tracker *tracker, int index, int steps);

/*
** Options
*/

void	options(int ac, char **av, t_flags *flags);
void	now_handle_it(t_flags *flags);

/*
** Bfs
*/

int		bfs(t_link *start);

/*
** Search
*/

int		search(t_link **que, int *q_count, int idx, t_tracker *tracker);

/*
** Augment
*/

int		augment(t_link *rev_link, int r_i, t_room *old_room, int backward);

/*
** Augment utilities
*/

void	set_flow(t_link *list, t_room *target_room, int flow);
void	delete_forward_room(t_room *room);
void	delete_prev_room(t_room *room);
void	remove_old_longer_path(t_room *room);

/*
** Algo
*/

int		pathfinder(void);

/*
** Sort
*/

void	sort_paths(t_path **path, int low, int high);

/*
** Mover
*/

void	insert_ant(t_ant_distr *distr, char *room_name, int ant_num);
void	ant_movement(void);

#endif
