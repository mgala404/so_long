#include "so_long.h"

void    ebro(t_vb *tat)
{
    char    *passi;
    char    *cc;

    cc =ft_itoa(tat->cc);
    passi = ft_itoa(tat->trav);
        image_to_win(tat, 0);
        mlx_string_put(tat->mlx,tat->mlx_win, 20, 10, 12321, passi);
        mlx_string_put(tat->mlx,tat->mlx_win, 40, 10, 12321, cc);
    free(cc);
    free(passi);
}