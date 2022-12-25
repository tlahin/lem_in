//header

#include "../includes/lem_in.h"

void	check_duplicate_command(int room_type)
{
	if (room_type != NORMAL_ROOM)
	{
		ft_printf("ERROR: error in command input\n");
		teminate_program();
	}
}

void	check_missing_special(void)
{
	if (!g_table->start || !g_table->end)
	{
		if(g_table->start == NOT_FOUND)
			ft_printf("ERROR: start room not found\n");
		if (g_table->end == NOT_FOUND)
			ft_printf("ERROR: end room not found\n");
		teminate_program();
	}
}