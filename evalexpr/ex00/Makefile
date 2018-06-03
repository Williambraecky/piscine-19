# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 09:49:58 by wbraeckm          #+#    #+#              #
#    Updated: 2018/05/20 10:59:26 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
SRCS = srcs/evalexpr.c srcs/evalexpr_strft.c srcs/evalexpr_operations.c srcs/evalexpr_resolve.c srcs/evalexpr_utils.c
INC = includes/

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRCS) -I $(INC) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all
