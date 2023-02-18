/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:06:56 by mgala             #+#    #+#             */
/*   Updated: 2023/01/21 15:07:07 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	close_win(t_vb *tat)
{
	int	y;

	y = 0;
	mlx_destroy_image(tat->mlx, tat->imag.benino);
	mlx_destroy_image(tat->mlx, tat->imag.beninoE);
	mlx_destroy_image(tat->mlx, tat->imag.p);
	mlx_destroy_image(tat->mlx, tat->imag.jesus);
	mlx_destroy_image(tat->mlx, tat->imag.dooropen);
	mlx_destroy_image(tat->mlx, tat->imag.door);
	mlx_destroy_image(tat->mlx, tat->imag.wall);
	mlx_destroy_image(tat->mlx, tat->imag.ground);
	mlx_destroy_window(tat->mlx, tat->mlx_win);
	while (tat->mappa[y])
	{
		free(tat->mappa[y]);
		free(tat->tempura[y]);
		y++;
	}
	free(tat->tempura);
	free(tat->mappa);
	mlx_destroy_display(tat->mlx);
	free(tat->mlx);
	exit (0);
}

void	accozzaglia(t_vb *tat)
{
	tat->size.y = ft_matlen(tat->mappa, tat);
	tat->size.x = strlencheck(tat->mappa, tat);
	cborders(tat);
	mapmatcheck(tat);
	checkpex(tat);
	tat->mlx = mlx_init();
	tat->mlx_win = mlx_new_window(tat->mlx,
			tat->size.x * 32, tat->size.y * 32, "so_long");
	ft_img_init(tat, &tat->imag.taglia);
	image_to_win(tat, 1);
	mlx_hook(tat->mlx_win, 17, 0, close_win, tat);
	mlx_hook(tat->mlx_win, 2, (1L << 0), ft_key_handler, tat);
	mlx_loop(tat->mlx);
}

int	main(int ac, char **av)
{
	t_vb	tat;
	char	*temp;

	tat.imag.taglia = 32;
	if (ac == 2)
	{
		tat.cc = 0;
		tat.trav = 0;
		tat.check = 0;
		temp = getmap(av[1]);
		tat.mappa = mapmat(temp, &tat);
		accozzaglia(&tat);
	}
	else
	{
		write(1, "e la mappa? coglione\n", 22);
		return (0);
	}
}
