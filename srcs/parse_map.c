//header

#include "lem_in.h"

static void parse_line(char *line, int *stage)
{
    static int   start_end;

    if (line[0] != '#')
    {
        if (*stage == 1 || ft_strchr(line, '-'))
        {
            //assign_room(line);
            *stage = 1;
        }
        else
        {
            //assign_room(line, start_end);
            start_end = 0;
        }
    }
    else
        read_command(line, &start_end);
}

static void parse_map(int ret, char *str)
{
    int stage;
    t_line line;
    char    current_line[500];
    
    line.start = 0;
    line.end = 0;
    stage = 0;
    while(line.start < ret)
    {
        line.index = 0;
        while(str[line.end] != '\n' && line.end < ret)
            current_line[line.index++] = str[line.end++];
        current_line[line.index] = 0;
        parse_line(current_line, &stage);
        line.end++;
        line.start = line.end;
    }
}

int read_map(void)
{
    char *str = (char*)malloc(sizeof(char) * 1000);
    int ret;

    ret = read(0, str, 10000);
    parse_map(ret, str);
    return (OK);
}