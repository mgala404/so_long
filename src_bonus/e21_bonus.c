#include "so_long_bonus.h"

void	apriporta(t_vb *tat)
{
	if (tat->cc == 0)
	{
		tat->check = 1;
		mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.beninoe,
			(tat->exit.x * 32), (tat->exit.y * 32));
		mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.ground,
			(tat->p_p.x * 32), (tat->p_p.y * 32));
	}
}
