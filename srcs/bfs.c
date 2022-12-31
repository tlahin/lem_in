//header

#include "../includes/lem_in.h"

int bfs(t_link *start)
{
	t_que		q;
	int			path;
	t_tracker	tracker[MAGIC_NUMBER];

	init_que(&q, start);
	tracker[0].steps = 0;
	path = 0;
	while (q.remaining--)
	{
		if (q.que[q.index]->crossed != g_crossed)
		{
			if (q.que[q.index]->to != g_table->end)
				q.remaining += search(q.que, &q.count, q.index, tracker);
		}
	}
	
}