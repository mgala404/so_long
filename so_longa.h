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
    char    type;
    void    *benino;
    void    *ground;
    void    *wall;
    void    *door;
    void    *intern_wall;
    void    *jesus;
    void    *penguin;
    int     taglia;
    char    fload;
} t_img;

typedef struct s_vb{
    void    *mlx;
    void    *mlx_win;
    t_cord  size;
    char  **mappa;
    t_img   imag;
    t_cord  p_p;
    int     cc;
} t_vb;

#endif
