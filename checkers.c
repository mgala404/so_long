#include "so_long.h"

//ritorna gli errori, liberatutti
void    ft_error(t_vb *tat)
{
    int y;

    y = 0;
    while(tat->mappa[y])
    {
        free(tat->mappa[y]);
        y++;
    }
    free(tat->mappa);
    exit (0);
}

//tutti i bordi sono muri?
void    cborders(t_vb *tat)
{
    int x;
    int y;

    y = 0;
    while (tat->mappa[y])
    {
        x = 0;
        while (tat->mappa[y][x])
        {
            if (tat->mappa[0][x] != '1')
                ft_error(tat);
            else if (tat->mappa[y][0] != '1')
                ft_error(tat);
            else if (tat->mappa[y][tat->size.x - 1] != '1')
                ft_error(tat);
            else if (tat->mappa[tat->size.y - 1][x] != '1')
               ft_error(tat);
            x++;
        }
        y++;
    }
}

void    ctr(t_vb *tat, char **map)
{
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] != '1' && map[y][x] != '0')
                ft_error(tat);
            x++;
        }
        y++;
    }
}

void	fill(char ***map, t_cord size, t_cord p_p, char to_fill)
{
	if (p_p.y < 0 || p_p.y >= size.y || p_p.x < 0 || p_p.x >= size.x
		|| *map[p_p.y][p_p.x] == to_fill)
		return;

	*map[p_p.y][p_p.x] = '1';
	fill(map, size, (t_cord){p_p.x - 1, p_p.y}, to_fill);
	fill(map, size, (t_cord){p_p.x + 1, p_p.y}, to_fill);
	fill(map, size, (t_cord){p_p.x, p_p.y - 1}, to_fill);
	fill(map, size, (t_cord){p_p.x, p_p.y + 1}, to_fill);
}

void	cexit(t_vb *tat, char **map, t_cord size, t_cord p_p)
{
	fill(&map, size, p_p, '1');
    ctr(tat, map);
}