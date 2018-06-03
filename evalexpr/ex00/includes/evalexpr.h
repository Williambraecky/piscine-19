/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbraeckm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 09:52:50 by wbraeckm          #+#    #+#             */
/*   Updated: 2018/05/20 10:59:03 by wbraeckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALEXPR_H
# define EVALEXPR_H

# include <unistd.h>
# include <stdlib.h>

char			*ft_remove_spaces(char *str);
int				ft_next_number();
int				ft_add(int i, int j);
int				ft_sub(int i, int j);
int				ft_mul(int i, int j);
int				ft_div(int i, int j);
int				ft_mod(int i, int j);
int				ft_resolve();
void			ft_putchar(char c);
void			ft_putnbr(int i);

typedef struct	s_opp
{
	char		str[2];
	int			priority;
	int			(*opp)(int, int);
}				t_opp;

t_opp			*ft_next_operation();
t_opp			*ft_get_operation(char c);

#endif
