#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <fcntl.h>

typedef struct s_dioc{
    void    *mlx;
    void    *mlx_win;
    char    *map;
} t_vb;

typedef struct s_img{
    void    *pg;
    void    *ground;
    void    *wall;
    void    *door;
    int     img_w;
    int     img_h;
}t_img;


#endif
