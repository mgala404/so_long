#include "so_long.h"

char    *getmap(char *path)
{
    int     fd;
    char    *str;
    char    *onzo;

    onzo = calloc (1, 1);
    fd = open(path, O_RDONLY);
    while (1)
    {
        str = get_next_line(fd);
        if (!str)
            break;    
        onzo = ft_freejoints(onzo, str);
        free(str);
    }
    free(str);
    close(fd);
    return (onzo);
}

char **mapmat(char *rawmap)
{
    char **map;

    map = ft_split(rawmap, '\n');
    free(rawmap);
    return(map);
}

void    mapmatcheck(char *rawmap, t_vb *tat)
{
    char **map;

    map = ft_split(rawmap, '\n');
    cexit(tat, map, tat->size, tat->p_p);
   // free(rawmap);
}

int     strlencheck(char **map, t_vb *tat)
{
    //int k;
    int x;
    int y;

    //k = ft_matlen(map);
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                tat->p_p.x = x;
                tat->p_p.y = y;
            }
            x++;
        }
        y++;
    }
    return (x);
}

int     ft_matlen(char **map, t_vb *tat)
{
    int y;

    y = 0;
    while(map[y])
    {
        strlencheck(map, tat);
        y++;
    }
    return (y);
}

