//header

#include "lem_in.h"

void read_command(char *str, int *start_end)
{
    if (!ft_strcmp(str, "##start"))
        *start_end = -1;
    else if (!ft_strcmp(str, "##end"))
        *start_end = 1;
    ft_printf("%s\n", str);
    ft_printf("%d\n", *start_end);
}