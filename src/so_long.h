#ifndef SO_LONG_H
# define SO_LONG_H
# define SIZE 32

# include "../mlx/mlx.h"
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_cord{
	int	x;
	int	y;
}	t_cord;

typedef struct s_img{
	void	*benino;
	void	*ground;
	void	*wall;
	void	*door;
	void	*dooropen;
	void	*p;
	void	*beninoe;
	int		taglia;
}	t_img;

typedef struct s_vb{
	void	*mlx;
	void	*mlx_win;
	t_cord	size;
	char	**mappa;
	char	**tempura;
	t_img	imag;
	t_cord	p_p;
	t_cord	p;
	t_cord	exit;
	int		cc;
	int		check;
	int		trav;
}	t_vb;

int		ft_key_handler(int keycode, t_vb *tat);
int		close_win(t_vb *tat);
char	*getmap(char *path);
char	**mapmat(char *rawmap, t_vb *tat);
int		ft_matlen(char **map, t_vb *tat);
void	ft_img_init(t_vb *tat, int *size);
void	image_to_win(t_vb *tat, int muro);
void	cexit(t_vb *tat, char **map, t_cord p_p);
void	cborders(t_vb *tat);
void	ctr(t_vb *tat, char **map);
int		strlencheck(char **map, t_vb *tat);
void	mapmatcheck(t_vb *tat, int x, int y);
void	checkpex(t_vb *tat);
void	check_flood(char **map, t_vb *tat, t_cord p_p);
void	ebro(t_vb *tat);
void	ft_muro(t_vb *tat, int y);
void	accozzaglia(t_vb *tat);
void	cveloce(t_vb *tat, int p, int e);
void	check_flood_logic_x(t_vb *tat, t_cord p, t_cord p_p, int mod);
void	check_flood_logic_y(t_vb *tat, t_cord p, t_cord p_p, int mod);
void	ft_error(t_vb *tat);
void	apriporta(t_vb *tat);

#endif
