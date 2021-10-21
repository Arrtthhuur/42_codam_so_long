# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abeznik <abeznik@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/03 15:23:47 by abeznik       #+#    #+#                  #
#    Updated: 2021/10/21 21:51:28 by abeznik       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SOURCES	=	main.c \
			map_read.c \

SRC_DIR	=	srcs

UTILS	=	get_next_line.c \
			get_next_line_utils.c \

UTL_DIR	=	utils

OBJ_DIR	=	obj

HEADER	=	includes

SRCS 	=	$(addprefix $(SRC_DIR)/,$(SOURCES))
OBJ_S 	=	$(patsubst %, $(OBJ_DIR)/srcs/%, $(SOURCES:.c=.o))

UTLS	=	$(addprefix $(UTL_DIR)/,$(UTILS))
OBJ_U 	=	$(patsubst %, $(OBJ_DIR)/utils/%, $(UTILS:.c=.o))

CC		=	gcc
RM		=	rm -f
FLAGS	=	-Werror -Wextra -Wall

all:		$(NAME)

$(NAME):	$(OBJ_S) $(OBJ_U)
	ar cr $(NAME) $(OBJ_S) $(OBJ_U)

$(OBJ_DIR)/srcs/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj/srcs
	$(CC) -c $(FLAGS) -I $(HEADER) -o $@ $<

$(OBJ_DIR)/utils/%.o: $(UTL_DIR)/%.c
	@mkdir -p obj/utils
	$(CC) -c $(FLAGS) -I $(HEADER) -o $@ $<

test:
	$(CC) -o so_long.out $(OBJ_S) $(OBJ_U)

clean:
	$(RM) $(OBJ_S) $(OBJ_U)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

del: fclean
	$(RM) *.out

re: fclean all

.PHONY: fclean re all clean