# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 15:11:07 by wbraeckm          #+#    #+#              #
#    Updated: 2018/05/16 17:18:02 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump
SRCS = srcs/ft_hexdump.c srcs/ft_atoi.c srcs/ft_strft.c srcs/ft_errors.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRCS) -I includes/ -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
