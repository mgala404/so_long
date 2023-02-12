#ifndef SO_LONG_H
#define SO_LONG_H

#define SIZE 32

#include "mlx/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <fcntl.h>

typedef struct s_cord{
    int     x;
    int     y;
} t_cord;

typedef struct s_img{
    void    *benino;
    void    *ground;
    void    *wall;
    void    *door;
    void    *dooropen;
    void    *jesus;
    void    *penguin;
    void    *beninoE;
    int     taglia;
} t_img;

typedef struct s_vb{
    void    *mlx;
    void    *mlx_win;
    t_cord  size;
    char  **mappa;
    t_img   imag;
    t_cord  p_p;
    t_cord  Exit;
    int	cc;
    int check;
} t_vb;

#endif
