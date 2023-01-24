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


int    close_win(t_vb *tat)
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

int main(int ac, char **av)
{
    t_vb *tat;

    tat = malloc (sizeof (t_vb));
    tat->map = getmap(av[1]);
    printf("%s\n", tat->map);
    tat->mlx = mlx_init();
    tat->mlx_win = mlx_new_window(tat->mlx, 580, 620, "so_short");
    mlx_hook(tat->mlx_win, 17, 0, close_win, &tat);
    mlx_loop(tat->mlx);
}

