#include "so_long.h"

//tutto cio che desideri se ci provi ce la puoi farcela
void    ft_img_init(t_vb *tat, int *size)
{
    tat->imag.benino = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/benny.xpm", size, size );
    tat->imag.ground = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/Floor.xpm", size, size );
    tat->imag.wall = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/Wall1.xpm", size, size );
    tat->imag.jesus = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/Jesusticazzi1.xpm", size, size );
    tat->imag.p = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/p.xpm", size, size );
    tat->imag.door = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/Exit.xpm", size, size );
    tat->imag.dooropen = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/Exitopen.xpm", size, size );
    tat->imag.beninoE = mlx_xpm_file_to_image(tat->mlx, "Ninjia&co/BeninoExit1.xpm", size, size );
}

void    imagineallthepeople(t_vb *tat, int  x, int  y)
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
    {
    mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.door, (x * 32), (y * 32));
    tat->Exit.x = x;
    tat->Exit.y = y;
    }
else if(tat->mappa[y][x] == 'J')
    mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.jesus, (x * 32), (y * 32));
else if(tat->mappa[y][x] == 'C')
    {
    mlx_put_image_to_window(tat->mlx, tat->mlx_win, tat->imag.p, (x * 32), (y * 32));
    tat->cc++;
    }
}

void    image_to_win(t_vb *tat)
{   
    int     x;
    int     y;

    tat->cc = 0;
    y = 0;
    while (tat->mappa[y])
    {
        x = 0;
        while (tat->mappa[y][x])
        {
        imagineallthepeople(tat, x, y);  
        x++;
        }
     y++;
    }
}