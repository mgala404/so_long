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


int    close_win(t_vb *tat)
{
    mlx_destroy_window(tat->mlx, tat->mlx_win);
    mlx_destroy_display(tat->mlx);
    free(tat->mlx);
    free(tat->mlx_win);
    free(tat);
    exit (0);
}

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
    }
    free(str);
    close(fd);
    return (onzo);
}

void    ft_img_init(t_vb *tat, t_img *mat)
{
    mat->img_h = 32;
    mat->img_w = 32;
    mat->pg = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/NinjaS1.xpm", &mat->img_h, &mat->img_w);
}

void    ft_num(t_vb *tat, t_img *mat)
{
    char     *mapcode;

    mapcode = getmap(tat->map);
    if(mapcode == "P")
        mlx_put_image_to_window(tat, tat->mlx_win, mat->pg, &mat->img_h, &mat->img_w);
}

int     ft_key_handler(int keycode, t_vb *tat)
{
    if(keycode == 65307)
        close_win(tat);
    return(0);
}
int main(int ac, char **av)
{
    t_vb *tat;
    t_img *mat;

    tat = malloc (sizeof (t_vb));
    mat = malloc (sizeof (t_img));
    tat->map = getmap(av[1]);
    //printf("\n%s\n", tat->map);
    tat->mlx = mlx_init();
    tat->mlx_win = mlx_new_window(tat->mlx, 320, 165, "so_short");
    ft_img_init(tat, mat);
    ft_num(tat, mat);
    mlx_hook(tat->mlx_win, 17, 0, close_win, &tat);
    mlx_key_hook(tat->mlx_win, ft_key_handler, &tat);
    mlx_loop(tat->mlx);
}
