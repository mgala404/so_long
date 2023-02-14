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
    void    *p;
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

int     ft_key_handler(int keycode, t_vb *tat);
int    close_win (t_vb *tat);
char    *getmap(char *path);
char **mapmat(char *rawmap);
int     ft_matlen(char **map);
void    ft_img_init(t_vb *tat, int *size);
void    image_to_win(t_vb *tat);
void	cexit(char **map, t_cord size, t_cord p_p);
void    cborders(t_vb *tat);

#endif
