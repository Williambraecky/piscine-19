# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 11:56:20 by nrouvroy          #+#    #+#              #
#    Updated: 2018/05/23 18:43:07 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = bsq
FLAGS = -Werror -Wextra -Wall
SRC = ./srcs/bsq.c ./srcs/bsq_strutils.c ./srcs/bsq_printer.c srcs/bsq_resolve.c srcs/bsq_utils.c srcs/bsq_parser_better.c srcs/bsq_list.c srcs/bsq_stdinput.c
OBJ = bsq.o bsq_strutils.o bsq_printer.o bsq_resolve.o bsq_utils.o bsq_parser_better.o bsq_list.o bsq_stdinput.o
INC = ./includes/

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(INC)

noflags:
	@gcc -o $(NAME) $(SRC) -I $(INC)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY: all $(NAME) noflags clean fclean re
