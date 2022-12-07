//header

#include "../includes/lem_in.h"

void	init_parser(t_parser *parser)
{
	char	str[STRING_SIZE];

	parser->ants = 0;
	parser->read_amount = read(1, str, STRING_SIZE);
	parser->map = str;
}
