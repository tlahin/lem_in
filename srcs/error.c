//header

#include "../includes/lem_in.h"

void	validate_ants(char c)
{
	if (!ft_isdigit(c))
	{
		ft_printf("ERROR: ants?!\n");
		teminate_program();
	}
}

void	check_ant_amount(t_parser *p)
{
	if (p->ants < 1)
	{
		ft_printf("ERROR: Invalid ant amount\n");
		teminate_program();
	}
}

void	check_duplicates_special(t_room *room, int room_state)
{
	if (room_state == START_ROOM && g_table->start != NULL)
	{
		ft_printf("ERROR: Duplicate start room found\n");
		free(room);
		teminate_program();
	}
	if (room_state == END_ROOM && g_table->end != NULL)
	{
		ft_printf("ERROR: Duplicate end room found\n");
		free(room);
		teminate_program();
	}
}

void	check_malloc(void *mem)
{
	if (mem == NULL)
	{
		ft_printf("ERROR: Failed to allocate memory\n");
		teminate_program();
	}
}
