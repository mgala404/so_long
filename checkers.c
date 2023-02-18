#include "so_long.h"

void	ft_error(t_vb *tat)
{
	int	y;

	y = 0;
	while (tat->mappa[y])
	{
		free(tat->mappa[y]);
		free(tat->tempura[y]);
		y++;
	}
	free(tat->tempura);
	free(tat->mappa);
	ft_printf("%s", "cambia sta mappa coglione\n");
	exit (0);
}

//tutti i bordi sono muri?
void	cborders(t_vb *tat)
{
	int	x;
	int	y;

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

void	ctr(t_vb *tat, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'P' )
				ft_error(tat);
			x++;
		}
		y++;
	}
}

void	check_flood(char **map, t_vb *tat, t_cord p_p)
{
	t_cord	p;

	map[p_p.y][p_p.x] = 'P';
	if (p_p.y > 0 && map[p_p.y - 1][p_p.x] != '1' && /
		&& map[p_p.y - 1][p_p.x] != 'P')
	{
		p.x = p_p.x;
		p.y = p_p.y - 1;
		check_flood(map, tat, p);
	}
	if (p_p.y < (tat->size.y - 1) && map[p_p.y + 1][p_p.x] != '1'
		&& map[p_p.y + 1][p_p.x] != 'P')
	{
		p.x = p_p.x;
		p.y = p_p.y + 1;
		check_flood(map, tat, p);
	}
	if (p_p.x < (tat->size.x - 1) && map[p_p.y][p_p.x + 1] != '1'
		&& map[p_p.y][p_p.x + 1] != 'P')
	{
		p.x = p_p.x + 1;
		p.y = p_p.y;
		check_flood(map, tat, p);
	}
	if (p_p.x > 0 && map[p_p.y][p_p.x - 1] != '1'
		&& map[p_p.y][p_p.x - 1] != 'P')
	{
		p.x = p_p.x - 1;
		p.y = p_p.y;
		check_flood(map, tat, p);
	}
}

void	checkpex(t_vb *tat)
{
	int	x;
	int	y;
	int	p;
	int	e;

	p = 0;
	e = 0;
	y = 0;
	while (tat->mappa[y])
	{
		x = 0;
		while (tat->mappa[y][x])
		{
			if (tat->mappa[y][x] == 'P' )
				p++;
			if (tat->mappa[y][x] == 'E' )
				e++;
			if (tat->cc == 0)
				ft_error(tat);
			x++;
		}
		y++;
	}
	if (p != 1 || e != 1)
	{
		ft_error(tat);
	}
}

void	cexit(t_vb *tat, char **map, t_cord p_p)
{
	check_flood(map, tat, p_p);
	ctr(tat, map);
}
