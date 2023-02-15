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

int    close_win (t_vb *tat)
{
    int y;

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
    while(tat->mappa[y])
    {
        free(tat->mappa[y]);
        y++;
    }
    free(tat->mappa);
    mlx_destroy_display(tat->mlx);
    free(tat->mlx);
    exit (0);
}

int main(int ac, char **av)
{
    t_vb tat;
    char    *temp;
    char    *tempura;

    tat.imag.taglia = 32;
    if (ac == 2)
    {
        tat.check = 0;
        temp = getmap(av[1]);
        tempura = temp;
        tat.mappa = mapmat(temp);
        tat.size.x = strlencheck(tat.mappa, &tat);
        tat.size.y = ft_matlen(tat.mappa);
        mapmatcheck(tempura, &tat);
        cborders(&tat);
        tat.mlx = mlx_init();
        tat.mlx_win = mlx_new_window(tat.mlx, tat.size.x * 32, tat.size.y * 32, "so_long");
        ft_img_init(&tat, &tat.imag.taglia);
        image_to_win(&tat);
        mlx_hook(tat.mlx_win, 17, 0, close_win, &tat);
        mlx_hook(tat.mlx_win, 2, (1L<<0), ft_key_handler, &tat);
        mlx_loop(tat.mlx);
    }
    else
    {
        write(1, "e la mappa? coglione", 21);
        return (0);
    }
}
