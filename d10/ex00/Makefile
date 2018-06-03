# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 08:26:55 by wbraeckm          #+#    #+#              #
#    Updated: 2018/05/14 12:10:38 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	cp -R srcs/ .
	cp -R includes/ .
	gcc -Wall -Wextra -Werror -c *.c
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.c
	rm -f *.o
	rm -f *.h

fclean: clean
	rm -f $(NAME)

re: fclean all

