/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 12:38:58 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/20 13:36:51 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# define INVALID_CHAR -1
# define INVALID_STRUCTURE -2
# define MATCHING_STRUCTURE 1
# define FIRST_LINE 0
# define MIDDLE 1
# define LAST_LINE 2

typedef struct		s_list
{
	char			*str;
	int				size;
	struct s_list	*next;
}					t_list;

typedef struct		s_rush_config
{
	char			top_left;
	char			top_right;
	char			bottom_left;
	char			bottom_right;
	char			walls;
	char			top_bottom;
}					t_rush_config;

typedef struct		s_checks
{
	char			*name;
	int				(*ft)(char *);
}					t_checks;

void				ft_putchar(char c);
void				ft_putnbr(int nbr);
int					ft_strlen(char *str);
char				*ft_strdup(char *str);
void				ft_strcat(char *str, char *to_add, int start);
char				*ft_parse_previous_input(void);
int					ft_count_lines(char *str);
int					ft_get_line_width(char *str);
int					ft_check_rush(t_rush_config config, char *input);
int					ft_is_space(char c);
int					ft_check_square(char *str);
void				ft_print_result(char *name, int width, int height, int nb);
int					ft_check_rectangle(char *input);
int					ft_square_is_char(int height, int width, int i, int j);
int					ft_check_square_rev(char *input);
int					ft_check_rev_rectangle(char *input);

#endif
