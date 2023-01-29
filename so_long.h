#ifndef SO_LONG_H
#define SO_LONG_H

#define SIZE 32

#include "mlx/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <fcntl.h>

typedef struct s_pos{
    char    type;
    struct  s_pos   *w;
    struct  s_pos   *a;
    struct  s_pos   *s;
    struct  s_pos   *d;
    char    fload;
} t_pos;

typedef struct s_cord{
    int     x;
    int     y;
} t_cord;


typedef struct s_dioc{
    void    *mlx;
    void    *mlx_win;
    char    *map;
    t_cord  coordin;
    t_pos   **mappa;
} t_vb;

typedef struct s_img{
    void    *pg;
    void    *ground;
    void    *wall;
    void    *door;
    void    *intern_wall;
    void    *snake;
    void    *potion;
    int     img_w;
    int     img_h;
} t_img;

#endif
