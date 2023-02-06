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

char **mapmat(char *rawmap)
{
    char **map;

    map = ft_split(rawmap, '\n');
    return(map);
}

int     ft_matlen(char **map)
{
    int y;

    y = 0;
    while(map[y])
        y++;
    return (y);
}

int     ft_key_handler(int keycode, t_vb *tat)
{
    int x = tat->p_p.x;
    int y = tat->p_p.y;
    if(keycode == 65307)
        close_win(tat);
    if ((keycode == 65363 || keycode == 100 ) && (tat->mappa[y][x+1] != '1'))
    {
        mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.ground, (tat->p_p.x  * 32), (tat->p_p.y  * 32));
        mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.benino, ((tat->p_p.x+1) * 32), (tat->p_p.y * 32));
        tat->mappa[tat->p_p.y][tat->p_p.x] = '0';
        tat->mappa[tat->p_p.y][tat->p_p.x+1] = 'P';
        tat->p_p.x += 1;
    }
    else if ((keycode ==  65361 || keycode == 97 )&& (tat->mappa[y][x-1] != '1'))
    {
        mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.ground, (tat->p_p.x  * 32), (tat->p_p.y  * 32));
        mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.benino, ((tat->p_p.x-1) * 32), (tat->p_p.y * 32));
        tat->mappa[tat->p_p.y][tat->p_p.x] = '0';
        tat->mappa[tat->p_p.y][tat->p_p.x-1] = 'P';
        tat->p_p.x -= 1;
    }
    else if ((keycode == 65362 || keycode == 119 ) && (tat->mappa[y-1][x] != '1'))
    {
        mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.ground, (tat->p_p.x  * 32), (tat->p_p.y  * 32));
        mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.benino, (tat->p_p.x * 32), ((tat->p_p.y-1) * 32));
        tat->mappa[tat->p_p.y][tat->p_p.x] = '0';
        tat->mappa[tat->p_p.y-1][tat->p_p.x] = 'P';
        tat->p_p.y -= 1;
    }
    else if ((keycode == 65364 || keycode == 115)&& (tat->mappa[y+1][x] != '1'))
    {
        mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.ground, (tat->p_p.x  * 32), (tat->p_p.y  * 32));
        mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.benino, (tat->p_p.x * 32), ((tat->p_p.y+1) * 32));
        tat->mappa[tat->p_p.y][tat->p_p.x] = '0';
        tat->mappa[tat->p_p.y+1][tat->p_p.x] = 'P';
        tat->p_p.y += 1;
    }
    return(0);
}

void    ft_img_init(t_vb *tat, int *size)
{
    tat->imag.benino = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/benny.xpm", size, size );
    tat->imag.ground = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/Floor.xpm", size, size );
    tat->imag.wall = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/Wall1.xpm", size, size );
    tat->imag.jesus = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/Jesusticazzi1.xpm", size, size );
    tat->imag.penguin = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/Penguin.xpm", size, size );
    tat->imag.door = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/Exit.xpm", size, size );
}

void    image_to_win(t_vb *tat)
{   
    int     x;
    int     y;

    y = 0;
    while (tat->mappa[y])
    {
    x = 0;
        while (tat->mappa[y][x])
        {
        if(tat->mappa[y][x] == '1')
            mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.wall, (x * 32), (y * 32));
        else if(tat->mappa[y][x] == '0')
            mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.ground, (x * 32), (y * 32));
        else if(tat->mappa[y][x] == 'P')
            {
                mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.benino, (x * 32), (y * 32));
                tat->p_p.x = x; 
                tat->p_p.y = y;
            }
        else if(tat->mappa[y][x] == 'E')
            mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.door, (x * 32), (y * 32));
        else if(tat->mappa[y][x] == 'J')
            mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.jesus, (x * 32), (y * 32));
        else if(tat->mappa[y][x] == 'C')
            mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.penguin, (x * 32), (y * 32));
        x++;
        }
     y++;  
    }
}


int main(int ac, char **av)
{
    t_vb tat;
    t_img *visual;
    t_cord  *cord;
    char    *temp;

    tat.imag.taglia = 32;
    if (ac == 2)
    {
    temp = getmap(av[1]);
    tat.mappa = mapmat(temp);
    tat.size.x = ft_strlen(tat.mappa[0]);
    tat.size.y = ft_matlen(tat.mappa);
    tat.mlx = mlx_init();
    tat.mlx_win = mlx_new_window(tat.mlx, tat.size.x * 32, tat.size.y * 32, "so_long");
    ft_img_init(&tat,  &tat.imag.taglia);
    image_to_win(&tat);
    mlx_hook(tat.mlx_win, 17, 0, close_win, &tat);
    mlx_key_hook(tat.mlx_win, ft_key_handler, &tat);
    mlx_loop(tat.mlx);
    }
    else
    {
        write(1, "e l argomento? coglione", 23);
        return (0);
    }
}
