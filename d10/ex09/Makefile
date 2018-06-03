# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 11:36:18 by wbraeckm          #+#    #+#              #
#    Updated: 2018/05/14 12:21:19 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_advanced_do-op

all: $(NAME)

$(NAME):
	cp -R srcs/ .
	cp -R includes/ .
	gcc -Wall -Wextra -Werror *.c -o $(NAME)

clean:
	rm -f *.c
	rm -f *.o
	rm -f *.h

fclean: clean
	rm -f $(NAME)

re: fclean all
