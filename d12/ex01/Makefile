# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 11:05:50 by wbraeckm          #+#    #+#              #
#    Updated: 2018/05/16 11:07:35 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
SRCS = srcs/ft_cat.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRCS) -I includes/ -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
