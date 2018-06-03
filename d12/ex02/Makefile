# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 12:10:45 by wbraeckm          #+#    #+#              #
#    Updated: 2018/05/16 18:32:00 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
SRCS = srcs/ft_tail.c srcs/ft_strft.c srcs/ft_atoi.c srcs/ft_strft_more.c

$(NAME): all

all:
	gcc -Wall -Wextra -Werror $(SRCS) -I includes/ -o $(NAME)

noflags:
	gcc $(SRCS) -I includes/ -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
