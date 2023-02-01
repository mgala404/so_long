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

/*void    map_cord(t_vb *tat, char *path)
{
    int     i;
    int     y;
    int     x;

    i = 0;
    y = 1;
    x = 0;
    while(path[x] != '\n')
        x++;
    tat->coordin.x = x;
    while(path[i] != '\0')
    {
        if(path[i] == '\n')
            y++;
        i++;
    }
    tat->coordin.y = y;
    tat->mappa = (t_pos **)malloc (sizeof(t_pos*) * (y + 1));
    while(y--)
        tat->mappa[y] = (t_pos*)malloc (sizeof(t_pos) * (x + 1));
}*/


int     ft_key_handler(int keycode, t_vb *tat)
{
    if(keycode == 65307)
        close_win(tat);
    return(0);
}

void    ft_img_init(t_img *mat, t_vb *tat)
{
    mat->img_h = 32;
    mat->img_w = 32;
    mat->benino = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/benny.xpm", &mat->img_h, &mat->img_w);
    mat->ground = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/Floor.xpm", &mat->img_h, &mat->img_w);
    mat->wall = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/Wall1.xpm", &mat->img_h, &mat->img_w);
    mat->jesus = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/Jesusticazzi1.xpm", &mat->img_h, &mat->img_w);
    mat->penguin = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/Penguin.xpm", &mat->img_h, &mat->img_w);
    mat->door = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/Exit.xpm", &mat->img_h, &mat->img_w);
}

void    image_to_win(t_vb *tat, t_cord cord)
{
    if(tat->mappa[cord.y][cord.x] = '1')
        mlx_put_image_to_window(tat, tat->mlx_win, tat->imag->wall, tat->size.x * 32, tat->size.y * 32);
    else if(tat->mappa[cord.y][cord.x] = '0')
        mlx_put_image_to_window(tat, tat->mlx_win, tat->imag->ground, tat->size.x * 32, tat->size.y * 32);
    else if(tat->mappa[cord.y][cord.x] = 'P')
        mlx_put_image_to_window(tat, tat->mlx_win, tat->imag->wall, tat->size.x * 32, tat->size.y * 32);
    else if(tat->mappa[cord.y][cord.x] = 'E')
        mlx_put_image_to_window(tat, tat->mlx_win, tat->imag->door, tat->size.x * 32, tat->size.y * 32);
    else if(tat->mappa[cord.y][cord.x] = 'J')
        mlx_put_image_to_window(tat, tat->mlx_win, tat->imag->jesus, tat->size.x * 32, tat->size.y * 32);
    else if(tat->mappa[cord.y][cord.x] = 'C')
        mlx_put_image_to_window(tat, tat->mlx_win, tat->imag->penguin, tat->size.x * 32, tat->size.y * 32);
}   
int ft_printmap(char **map, t_vb tat)
{
    int y;
    int x;
    t_cord pos;

    y = 0;
    while(map[y])
    {
        x = 0;
        pos.y = y;
        while(map[y][x])
        {
            pos.x = x;
            image_to_win(&tat, pos);
            x++;
        }
        y++;
    }
    return (0);
}
int main(int ac, char **av)
{
    t_vb *tat;
    t_img *visual;
    t_cord  *cord;
    
    if (ac == 2)
    {
    tat = malloc (sizeof (t_vb));
    visual = malloc (sizeof (t_img));
    tat->mappa = getmap(av[1]);
    //printf("\n%s\n", tat->map);
    //printf("\n%p\n", tat->mlx_win);
    //map_cord(tat, tat->map);
    tat->size.x = ft_strlen(tat->mappa[0]);
    tat->size.y = ft_matlen(tat->mappa);
    tat->mlx = mlx_init();
    tat->mlx_win = mlx_new_window(tat->mlx, tat->size.x * 32, tat->size.y * 32, "so_long");
    ft_img_init(tat->imag, tat);
    ft_printmap(tat->mappa, *tat);
    mlx_hook(tat->mlx_win, 17, 0, close_win, &tat);
    mlx_key_hook(tat->mlx_win, ft_key_handler, &tat);
    mlx_loop(tat->mlx);
    }
    else
    {
        write(1, "e l argomento? coglione", 23);
        return (0);
    }
}
