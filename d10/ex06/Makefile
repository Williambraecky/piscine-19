# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 09:15:51 by wbraeckm          #+#    #+#              #
#    Updated: 2018/05/14 12:10:08 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

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
