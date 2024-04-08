##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=       main.c	\
			my_window.c	\
			my_str_to_word_array.c	\
			my_getnbr.c	\
			parsing.c	\
			planes_infos.c	\
			create_tower.c	\
			create_plane.c	\
			draw_plane.c	\
			updt_plane_pos.c	\
			deleting_node.c	\
			my_putchar.c	\

CFLAGS += -g -I./include

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

all:	$(NAME)
$(NAME)	: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
