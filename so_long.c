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

void    map_cord(t_vb *tat, char *path)
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
}

void    ft_img_init(t_vb *tat, t_img *mat)
{
    int     i;

    i = 0;
    mat->img_h = 32;
    mat->img_w = 32;
    while(i <= 2)
    {
        if(/*coordinate x e y == coordinate di exit*/)
        {
            mat->pg = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/BeninoExit.xpm", &mat->img_h, &mat->img_w);
            break;
        }
        else if(i = 0)
            mat->pg = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/benny.xpm", &mat->img_h, &mat->img_w);
        else if(i = 1)
            mat->pg = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/benny1.xpm", &mat->img_h, &mat->img_w);
        else if(i = 2)
        {
            mat->pg = mlx_xpm_file_to_image(tat->mlx, "/Ninjia&co/benny2.xpm", &mat->img_h, &mat->img_w);
            i = 0;
        } 
        if(keycode == 65361 || keycode == 65363 || keycode == 65362 || keycode 65364)
            i++;
    }
}

void    image_to_win()
{
    	mlx_put_image_to_window(t_vb,t_win_list *win,t_img *img, int x,int y)
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
    
    if (ac == 2)
    {
    tat = malloc (sizeof (t_vb));
    mat = malloc (sizeof (t_img));
    tat->map = getmap(av[1]);
    //printf("\n%s\n", tat->map);
    //printf("\n%p\n", tat->mlx_win);
    map_cord(tat, tat->map);
    image_to_win(tat, tat->map, tat->mlx_win, );
    tat->mlx = mlx_init();
    tat->mlx_win = mlx_new_window(tat->mlx, tat->coordin.x * SIZE, tat->coordin.y * SIZE, "so_short");
    ft_img_init(tat, mat);
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
