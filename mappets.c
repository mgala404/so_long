#include "so_long.h"

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
        free(str);
    }
    free(str);
    close(fd);
    return (onzo);
}

char **mapmat(char *rawmap)
{
   // int y;
   // y =0;
    char **map;

    map = ft_split(rawmap, '\n');
    //cexit(map);
   //  while(map)
 //   {
   //     free(map[y]);
  //      y++;
  //  }
   // free(map);
   // map = ft_split(rawmap, '\n');
    free(rawmap);
    return(map);
}

int     ft_matlen(char **map)
{
    int y;

    y = 0;
    while(map[y])
        y++;
    return (y);
}
