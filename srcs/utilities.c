//header

#include "../includes/lem_in.h"

t_link	*add_elist(t_room *from_room, t_room *to_room)
{
	t_link	*link;

	link = (t_link *)ft_memalloc(sizeof(t_link));
	check_malloc((void *)link);
	set_link(link, from_room, to_room, 0);
	link->next = from_room->link;
	from_room->link = link;
	return (link);
}

void	set_link(t_link *link, t_room *from, t_room *to, int flow)
{
	link->from = from;
	link->to = to;
	link->flow = flow;
	link->crossed = 0;
}

void	set_tracker(t_tracker *tracker, int index, int steps)
{
	tracker->index = index;
	tracker->steps = steps;
}

void	teminate_program(void)
{
	free_everything();
	exit(0);
}
