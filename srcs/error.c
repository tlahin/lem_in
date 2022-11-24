//header

#include "lem_in.h"

void    validate_ants(char c)
{
    if (!ft_isdigit(c))
    {
        ft_printf("ERROR: ants?!\n");
        //terminate
    }
}

void    check_ant_amount(void)
{
    if (g_ant < 1)
    {
        ft_printf("ERROR: Invalid ant amount\n");
        //terminate
    }
}