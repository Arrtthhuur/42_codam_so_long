# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abeznik <abeznik@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/03 15:23:47 by abeznik       #+#    #+#                  #
#    Updated: 2021/10/26 21:16:42 by abeznik       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SOURCES	=	main.c \
			map_parsing.c \

SRC_DIR	=	srcs

UTILS	=	get_next_line.c \
			get_next_line_utils.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstsize.c \
			ft_lstlast.c \

UTL_DIR	=	utils

OBJ_DIR	=	obj

HEADER	=	includes

SRCS 	=	$(addprefix $(SRC_DIR)/,$(SOURCES))
OBJ_S 	=	$(patsubst %, $(OBJ_DIR)/srcs/%, $(SOURCES:.c=.o))

UTLS	=	$(addprefix $(UTL_DIR)/,$(UTILS))
OBJ_U 	=	$(patsubst %, $(OBJ_DIR)/utils/%, $(UTILS:.c=.o))

CC		=	gcc
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ_S) $(OBJ_U)
	ar cr $(NAME) $(OBJ_S) $(OBJ_U)

$(OBJ_DIR)/srcs/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj/srcs
	$(CC) -c $(FLAGS) -I $(HEADER) -o $@ $<

$(OBJ_DIR)/utils/%.o: $(UTL_DIR)/%.c
	@mkdir -p obj/utils
	$(CC) -c $(FLAGS) -I $(HEADER) -o $@ $<

test:	$(OBJ_S) $(OBJ_U)
	$(CC) -o so_long.out $(OBJ_S) $(OBJ_U)
	./so_long.out

simple_valid:
	./so_long.out simple_valid.ber
	
min_valid:
	./so_long.out min_valid.ber

simple_invalid:
	./so_long.out invalid.ber

clean:
	$(RM) $(OBJ_S) $(OBJ_U)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

del: fclean
	$(RM) *.out

debug:
	gcc -g3 -o so_long.out $(SRCS) $(UTLS)
	lldb so_long.out
	
re: fclean all

.PHONY: fclean re all clean