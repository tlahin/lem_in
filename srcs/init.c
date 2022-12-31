//header

#include "../includes/lem_in.h"

void	init_parser(t_parser *parser)
{
	char	str[STRING_SIZE];

	parser->ants = 0;
	parser->read_amount = read(1, str, STRING_SIZE);
	parser->map = str;
}

void	init_que(t_que *q, t_link *start)
{
	q->que[0] = start;
	q->remaining = 1;
	q->count = 1;
	q->index = 0;
}
