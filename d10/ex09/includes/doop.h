/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:25:45 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/14 12:31:10 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include <unistd.h>

void			ft_add(int i, int j);
void			ft_sub(int i, int j);
void			ft_mul(int i, int j);
void			ft_div(int i, int j);
void			ft_mod(int i, int j);
void			ft_usage(int i, int j);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				ft_is_numeric(char *str);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int i);
int				ft_str_equals(char *s1, char *s2);

typedef struct	s_opp
{
	char	str[2];
	void	(*fptr)(int, int);
}				t_opp;

#endif
