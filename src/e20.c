#include "so_long.h"

void	mvsx(t_vb *tat, int x, int y)
{
	if (tat->mappa[y][x - 1] != 'E')
	{
		mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.ground,
			(tat->p_p.x * 32), (tat->p_p.y * 32));
		mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.benino,
			((tat->p_p.x - 1) * 32), (tat->p_p.y * 32));
		if (tat->mappa[tat->p_p.y][tat->p_p.x - 1] == 'C')
			tat->cc--;
		if (tat->cc == 0)
			mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.dooropen,
				(tat->exit.x * 32), (tat->exit.y * 32));
		tat->mappa[tat->p_p.y][tat->p_p.x] = '0';
		tat->mappa[tat->p_p.y][tat->p_p.x - 1] = 'P';
		tat->p_p.x -= 1;
	}
	else if (tat->mappa[y][x - 1] == 'E')
	{
		apriporta(tat);
	}
	tat->trav++;
}

void	mvdx(t_vb *tat, int x, int y)
{
	if (tat->mappa[y][x + 1] != 'E')
	{
		mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.ground,
			(tat->p_p.x * 32), (tat->p_p.y * 32));
		mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.benino,
			((tat->p_p.x + 1) * 32), (tat->p_p.y * 32));
		if (tat->mappa[tat->p_p.y][tat->p_p.x + 1] == 'C')
			tat->cc--;
		if (tat->cc == 0)
			mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.dooropen,
				(tat->exit.x * 32), (tat->exit.y * 32));
		tat->mappa[tat->p_p.y][tat->p_p.x] = '0';
		tat->mappa[tat->p_p.y][tat->p_p.x + 1] = 'P';
		tat->p_p.x += 1;
	}
	else if (tat->mappa[y][x + 1] == 'E')
	{
		apriporta(tat);
	}
	tat->trav++;
}

void	mvsv(t_vb *tat, int x, int y)
{
	if (tat->mappa[y - 1][x] != 'E')
	{
		mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.ground,
			(tat->p_p.x * 32), (tat->p_p.y * 32));
		mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.benino,
			(tat->p_p.x * 32), ((tat->p_p.y - 1) * 32));
		if (tat->mappa[tat->p_p.y - 1][tat->p_p.x] == 'C')
			tat->cc--;
		if (tat->cc == 0)
			mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.dooropen,
				(tat->exit.x * 32), (tat->exit.y * 32));
		tat->mappa[tat->p_p.y][tat->p_p.x] = '0';
		tat->mappa[tat->p_p.y - 1][tat->p_p.x] = 'P';
		tat->p_p.y -= 1;
	}
	else if (tat->mappa[y - 1][x] == 'E')
	{
		apriporta(tat);
	}
	tat->trav++;
}

void	mvgx(t_vb *tat, int x, int y)
{
	if (tat->mappa[y + 1][x] != 'E')
	{
		mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.ground,
			(tat->p_p.x * 32), (tat->p_p.y * 32));
		mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.benino,
			(tat->p_p.x * 32), ((tat->p_p.y + 1) * 32));
		if (tat->mappa[tat->p_p.y + 1][tat->p_p.x] == 'C')
			tat->cc--;
		if (tat->cc == 0)
			mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.dooropen,
				(tat->exit.x * 32), (tat->exit.y * 32));
		tat->mappa[tat->p_p.y][tat->p_p.x] = '0';
		tat->mappa[tat->p_p.y + 1][tat->p_p.x] = 'P';
		tat->p_p.y += 1;
	}
	if (tat->mappa[y + 1][x] == 'E')
	{
		apriporta(tat);
	}
	tat->trav++;
}

int	ft_key_handler(int keycode, t_vb *tat)
{
	int	x;
	int	y;

	x = tat->p_p.x;
	y = tat->p_p.y;
	if (tat->check == 1)
		close_win(tat);
	if (keycode == 65307)
		close_win(tat);
	if ((keycode == 65363 || keycode == 100)
		&& (tat->mappa[y][x + 1] != '1'))
		mvdx(tat, x, y);
	else if ((keycode == 65361 || keycode == 97)
		&& (tat->mappa[y][x - 1] != '1'))
		mvsx(tat, x, y);
	else if ((keycode == 65362 || keycode == 119)
		&& (tat->mappa[y - 1][x] != '1'))
		mvsv(tat, x, y);
	else if ((keycode == 65364 || keycode == 115)
		&& (tat->mappa[y + 1][x] != '1'))
		mvgx(tat, x, y);
	ebro(tat);
	return (0);
}
