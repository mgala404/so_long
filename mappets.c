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

char **mapmat(char *rawmap, t_vb *tat)
{
    char **map;

    map = ft_split(rawmap, '\n');
    tat->tempura = ft_split(rawmap, '\n');
    free(rawmap);
    return(map);
}

void    mapmatcheck(t_vb *tat)
{
    cexit(tat, tat->tempura, tat->p_p);
   // free(rawmap);
}

int     strlencheck(char **map, t_vb *tat)
{
    //int k;
    int x;
    int y;

    tat->cc = 0;
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
            else if (map[y][x] == 'C')
                tat->cc += 1;
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

