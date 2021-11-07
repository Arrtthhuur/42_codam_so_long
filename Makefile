# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abeznik <abeznik@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/03 15:23:47 by abeznik       #+#    #+#                  #
#    Updated: 2021/11/07 17:47:12 by abeznik       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

MLX_NAME = libmlx.dylib

SOURCES	=	main.c \
			map_parsing.c \
			map_len.c \
			map_walls.c \
			map_ecp.c \

SRC_DIR	=	srcs

UTILS	=	get_next_line.c \
			get_next_line_utils.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \

UTL_DIR	=	utils

OBJ_DIR	=	obj

HEADER	=	includes

SRCS 	=	$(addprefix $(SRC_DIR)/,$(SOURCES))
OBJ_S 	=	$(patsubst %, $(OBJ_DIR)/srcs/%, $(SOURCES:.c=.o))

UTLS	=	$(addprefix $(UTL_DIR)/,$(UTILS))
OBJ_U 	=	$(patsubst %, $(OBJ_DIR)/utils/%, $(UTILS:.c=.o))

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(MLX_NAME) $(OBJ_S) $(OBJ_U)
	$(CC) $(OBJ_S) $(OBJ_U) -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX_NAME):
	make -C ./mlx
	cp ./mlx/libmlx.dylib libmlx.dylib

$(OBJ_DIR)/srcs/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj/srcs
	$(CC) -c $(CFLAGS) -I $(HEADER) -o $@ $<

$(OBJ_DIR)/utils/%.o: $(UTL_DIR)/%.c
	@mkdir -p obj/utils
	$(CC) -c $(CFLAGS) -I $(HEADER) -o $@ $<

test:	$(OBJ_S) $(OBJ_U)
	$(CC) -o $(NAME) $(OBJ_S) $(OBJ_U)
	./so_long

simple_valid:
	./so_long simple_valid.ber
	
min_valid:
	./so_long min_valid.ber

simple_invalid:
	./so_long invalid.ber

clean:
	$(RM) $(OBJ_S) $(OBJ_U)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_NAME)
	make clean -C ./mlx

del: fclean
	$(RM) *.out
	rm -rf *.dSYM

debug:
	gcc -g3 -o so_long $(SRCS) $(UTLS)
	lldb so_long
	
re: fclean all

.PHONY: fclean re all clean