NAME = so_long

LIBFT = libft/libft.a

MINILIBX = mlx/libmlx.a

SRC = so_long.c \
	imagine_ucan.c \
	e20.c \
	mappets.c \
	checkers.c\
	etravers.c\
	
BNS = so_long_bonus.c
	
FLAGS = -no-pie -Wall -Werror -Wextra -g

LINKS = -lm -lX11 -lXext

MAPS = map.ber

all:
	gcc $(SRC) $(MINILIBX) $(LIBFT) $(LINKS) $(FLAGS) -o $(NAME)
	

fclean:   	libfclean
		rm -rf $(NAME)
		rm -rf maps/list_maps.txt
		
re: clean all

.PHONY: all re clean fclean maps

.SILENT:
