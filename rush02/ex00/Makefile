# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 12:36:58 by wbraeckm          #+#    #+#              #
#    Updated: 2018/05/20 13:37:27 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
SRC = srcs/rush02.c srcs/rush02_ftstr.c srcs/rush02_parser.c srcs/rush02_checker.c srcs/rush02_ftstr2.c srcs/rush02_square.c srcs/rush02_rectangle.c srcs/rush02_reverse_square.c srcs/rush02_rev_rectangle.c
INC = includes/

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) -I $(INC) -o $(NAME)

noflags:
	gcc $(SRC) -I $(INC) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all
