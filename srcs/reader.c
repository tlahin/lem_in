//header

#include "../includes/lem_in.h"

int reader(int fd)
{
    int ret;
    char *line;

    if (get_next_line(fd, &line) == -1)
    {
        ft_printf("Error reading the file\n");
        return (-1);
    }
    else
    {
        ft_printf("line: %s\n", line);
        return (0);
    }
}