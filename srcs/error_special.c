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