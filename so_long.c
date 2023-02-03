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

void    ft_img_init(t_vb *tat, int *size)
{
    tat->imag.benino = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/benny.xpm", size, size );
    tat->imag.ground = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/Floor.xpm", size, size );
    tat->imag.wall = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/Wall1.xpm", size, size );
    tat->imag.jesus = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/Jesusticazzi1.xpm", size, size );
    tat->imag.penguin = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/Penguin.xpm", size, size );
    tat->imag.door = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/Exit.xpm", size, size );
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
            mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.benino, (x * 32), (y * 32));
        else if(tat->mappa[y][x] == 'E')
            mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.door, (x * 32), (y * 32));
        else if(tat->mappa[y][x] == 'J')
            mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.jesus, (x * 32), (y * 32));
        else if(tat->mappa[y][x] == 'C')
            mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.penguin, (x * 32), (y * 32));
        }
        x++;
    }
    y++;
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
    //visual = malloc (sizeof (t_img));
    temp = getmap(av[1]);
    tat.mappa = mapmat(temp);
    free (temp);
    //printf("\n%s\n", tat->mappa);
    //printf("\n%p\n", tat->mlx_win);
    //map_cord(tat, tat->map);
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
